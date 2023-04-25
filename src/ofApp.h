#pragma once

#include "ofMain.h"
#include "tweet.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <array>
#include <iostream>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		//of functions
		void keyPressed(int key);	
		void mousePressed(int x, int y, int button);
		//custom made functions
		string wrapString(string text, int width);
		void queryHandler(bool isCount, string query);
		void loadData();
		void printTweetInfo();
		void outputCountedQuery(string query);
		void instructionPanel();
		
		//variables
		ifstream inFile;
		vector<Tweet> tweets;
		vector<Tweet> results;
		int page, countTweets, start, stop, textStartPos, arrowSize, arrowY;
		ofTrueTypeFont fontTitle, fontHeader, fontText;
		stringstream tweetInfo;
		string wrappedText, state;
		array<string, 10> headers;
		ofImage upArrowKey, downArrowKey, leftArrowKey, rightArrowKey;
		ofRectangle upArrowButton, downArrowButton, leftArrowButton, rightArrowButton;
};