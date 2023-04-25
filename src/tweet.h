#pragma once

#include "ofMain.h"

class Tweet {
	string date;
	string time;
	string tweet;
public: 
	Tweet();
	Tweet(string date, string time, string tweet);

	//getters
	string getDate();
	string getTime();
	string getTweet();

};