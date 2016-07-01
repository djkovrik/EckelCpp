/*
Modify HTMLStripper.cpp so that when it encounters a tag,
it displays the tag’s name, then displays the file’s contents
between the tag and the file’s ending tag. Assume no nesting
of tags, and that all tags have ending tags (denoted with </TAGNAME>).
*/

#include <cassert>
#include <cmath>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

#include "ex09_ReplaceAll.h"

using namespace std;

string& stripHTMLTags(string& s, string& t) {
	static bool inTag = false;
	static bool firstTag = true;
	bool done = false;
	string content;
	while(!done) {
		if(inTag) {
		// The previous line started an HTML tag
		// but didn't finish. Must search for '>'.
			size_t rightPos = s.find('>');
			if(rightPos != string::npos) {
				inTag = false;
				s.erase(0, rightPos + 1);
			}
			else {
				done = true;
				s.erase();
			}
		}
		else {
		// Look for start of tag:
			size_t leftPos = s.find('<');
			if(leftPos != string::npos) {
			// See if tag close is in this line:
				size_t rightPos = s.find('>');
				if(rightPos == string::npos) {
					inTag = done = true;
					content = s.substr(0, leftPos);
					t += content + '\n';
					content.clear();
					s.erase(leftPos);
				}
				else {
					if (firstTag) {
						size_t tagLength = rightPos - leftPos + 1;
						t += "Tag name: " + s.substr(leftPos, tagLength) + '\n';
						content = s.substr(rightPos + 1);
						size_t nextPos = content.find('<');
						if (nextPos != string::npos)
							content.erase(nextPos);
						t += "Tag content: " + content + '\n';
						content.clear();
					}
					firstTag = !firstTag;
					s.erase(leftPos, rightPos - leftPos + 1);
				}
			}
			else
				done = true;
		}
	}
	// Remove all special HTML characters
	replaceAll(s, "&lt;", "<");
	replaceAll(s, "&gt;", ">");
	replaceAll(s, "&amp;", "&");
	replaceAll(s, "&nbsp;", " ");
	// Etc...
	return s;
}

int main() {

	ifstream in("ex09.html");
	string s;
	string tags;
	while(getline(in, s))
		if(!stripHTMLTags(s, tags).empty())
			cout << s << endl;
			cout << tags << endl;
}
