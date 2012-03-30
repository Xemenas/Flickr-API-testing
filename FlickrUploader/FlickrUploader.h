// FlickrUploader.h

#pragma once
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

namespace FlickrUploader {

	class FlickrUpload
	{
		// TODO: Add your methods for this class here.
		public:
			//Used in making authentication calls
			//However those are not implemented yet
			static char* getMD5CheckSum(char* thingToSum)
			{
				MD5 md5;
				return md5.digestString(thingToSum);
			}

			//This function will search for photos with the tag(s) passed in
			//and print out the information about the photos

			static void searchForTag(string tags)
			{
				string searchLink = "http://flickr.com/services/rest/?method=flickr.photos.search&api_key=5791cb8ea02f7539d5a6fa1dbea3dd11&tags=";
				searchLink.append(tags);
				String^ str2 = gcnew String(searchLink.c_str());

				HttpWebRequest^ myReq = dynamic_cast<HttpWebRequest^>(WebRequest::Create(str2));

				// Set some reasonable limits on resources used by this request
				myReq->MaximumAutomaticRedirections = 4;
				myReq->MaximumResponseHeadersLength = 4;

				// Set credentials to use for this request.
				myReq->Credentials = CredentialCache::DefaultCredentials;
				HttpWebResponse^ response = dynamic_cast<HttpWebResponse^>(myReq->GetResponse());
				Console::WriteLine( "Content length is {0}", myReq->ContentLength );
				Console::WriteLine( "Content type is {0}", myReq->ContentType );

				// Get the stream associated with the response.
				Stream^ receiveStream = response->GetResponseStream();

				// Pipes the stream to a higher level stream reader with the required encoding format. 
				StreamReader^ readStream = gcnew StreamReader( receiveStream,Encoding::UTF8 );
				Console::WriteLine( "Response stream received." );
				Console::WriteLine( readStream->ReadToEnd() );
				response->Close();
				readStream->Close();
			}
	};
}