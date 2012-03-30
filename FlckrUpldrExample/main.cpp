#include "FlickrUploader.h"
#using <mscorlib.dll>
#using <System.dll>
#include <string>
#include <iostream>
#include "md5.h"

using namespace System;
using namespace System::IO;
using namespace System::Net;
using namespace System::Text;
using namespace std;

int main(int argc, char argv[])
{
	string tags;
	cout << "Please enter the comma delimited tags you'd like to search Flickr for: ";
		getline(cin,tags);
	FlickrUploader::FlickrUpload::searchForTag(tags);
	cin.get();
}