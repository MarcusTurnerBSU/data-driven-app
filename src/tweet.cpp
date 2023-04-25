#include "tweet.h"

Tweet::Tweet() {

}

Tweet::Tweet(string date, string time, string tweet) {
	this->date = date;
	this->time = time;
	this->tweet = tweet;
}

//getters
string Tweet::getDate() {
	return date;
}

string Tweet::getTime() {
	return time;
}

string Tweet::getTweet() {
	return tweet;
}