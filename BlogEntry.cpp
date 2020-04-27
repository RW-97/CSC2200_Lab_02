
using namespace std;

#include "BlogEntry.h"

// Uses default constructors of all objects? (empty strings & current
// date)
BlogEntry::BlogEntry() {
}

BlogEntry::BlogEntry(const Text& initAuthor, const Text& initContents)
    : author(initAuthor), contents(initContents)
{
}

Text BlogEntry::getAuthor() const {
    
}

Text BlogEntry::getContents() const {
    
}

Date BlogEntry::getCreateDate() const {
    
}

Date BlogEntry::getModifyDate() const {
    
}

void BlogEntry::printHTML( ostream& out ) const {
    out << "<html>\n<body>\n"
        << "<h1>" << author << "</h1>\n"
	<< "<p>" << endl
	<< contents << endl
	<< "</p>" << endl
	<< "<p>" << endl
	<< "Created: " << created << endl
	<< "</p>" << endl
	<< "<p>" << endl
	<< "Last modified: " << modified << endl
	<< "</p>" << endl
	<< "</body>\n</html>" << endl;
}

void BlogEntry::setAuthor(const Text& newAuthor) {
    author = newAuthor;
    modified = Date();
}

void BlogEntry::setContents(const Text& newContents) {
    contents = newContents;
    modified = Date();
}

// requires operator<<() defined for Date
void BlogEntry::showStructure() const {

    cout << "Author: " << author << endl;
    cout << "Created: " << created << endl;
    cout << "Modified: " << modified << endl;
    cout << "Content: " << contents << endl;
    
}
