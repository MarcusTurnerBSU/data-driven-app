#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundColor(48, 40, 138);
	loadData();
	//initialising variables
	textStartPos = 20;
	countTweets = 0;
	page = 0;
	arrowSize = 15;
	arrowY = 722;
	state = "count";
	//multi lines for read-ability
	headers = { "Number of Tweets", "Number of Money Tweets", "Number of Politics Tweets", "Number of Paris Tweets", 
		"Number of DreamWorks Tweets", "Number of Uber Tweets", "Number of Taylor Swift Tweets", 
		"Number of Sandwich Tweets", "Number of Driving Tweets", "Number of Football Tweets" };
	//loading in fonts and images
	fontTitle.load("font.ttf", 50);
	fontHeader.load("font.ttf", 25);
	fontText.load("text.ttf", 15);
	upArrowKey.load("up-arrow-key.png");
	downArrowKey.load("downwards-arrow-key.png");
	leftArrowKey.load("left-arrow-key.png");
	rightArrowKey.load("right-arrow-key.png");
	upArrowButton.set(880, arrowY, arrowSize, arrowSize);
	downArrowButton.set(985, arrowY, arrowSize, arrowSize);
	leftArrowButton.set(767, arrowY, arrowSize, arrowSize);
	rightArrowButton.set(845, arrowY, arrowSize, arrowSize);
}

//--------------------------------------------------------------
void ofApp::update() {
	
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(31, 27, 83);
	ofDrawRectRounded(10, 145, 1006, 540, 7);
	//no tints will appear
	ofSetColor(255);
	fontTitle.drawString("Tweet Searching", 315, 70);
	fontHeader.drawString(headers[page], textStartPos, 125);
	wrappedText = wrapString(tweetInfo.str(), ofGetWidth() - 200);
	fontText.drawString(wrappedText, textStartPos, 175);
	instructionPanel();
	fontText.drawString("Page " + to_string(page + 1), textStartPos, 735);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	//these key presses are changing the pages
	if (key == OF_KEY_LEFT && page != 0) {
		countTweets = 0;
		page--;
	}
	else if (key == OF_KEY_RIGHT && page != 9) {
		countTweets = 0;
		page++;
	}
	
	//these key presses are for scrolling up and down
	if (state == "print") {
		if (key == OF_KEY_UP || key == OF_KEY_DOWN) {
			int leftOverTweets = results.size() - stop;
			if (key == OF_KEY_DOWN /*and screen is not all the way up*/) {
				if (stop + 5 <= results.size()) {
					stop += 5;
					start += 5;
					printTweetInfo();
				}
				else if (leftOverTweets > 0) {
					start += 5;
					stop += results.size() % 5;
					printTweetInfo();
				}
			}
			if (key == OF_KEY_UP) {//tweets shift up to show more tweets
				if (leftOverTweets == 0 && results.size() % 5 != 0) {
						start -= 5;
						stop -= results.size() % 5;
						printTweetInfo();
				}
				else if (start != 0) {
					start -= 5;
					stop -= 5;
					printTweetInfo();
				}

			}
		}
	}
	if (key == OF_KEY_RIGHT || key == OF_KEY_LEFT) {
		if (page == 0) {
			tweetInfo.str("");
			tweetInfo << "The amount of tweets in the file are: " << tweets.size();
		}
		else if (page == 1) {
			
			queryHandler(true, "money");
		}
		else if (page == 2) {
			queryHandler(true, "politics");
		}
		else if (page == 3) {
			queryHandler(false, "Paris");
		}
		else if (page == 4) {
			queryHandler(false, "DreamWorks");
		}
		else if (page == 5) {
			queryHandler(false, "Uber");
		}
		else if (page == 6) {
			queryHandler(false, "Taylor Swift");
		}
		else if (page == 7) {
			queryHandler(true, "sandwich");
		}
		else if (page == 8) {
			queryHandler(true, "driving");
		}
		else if (page == 9) {
			queryHandler(false, "football");
		}
	}
}

void ofApp::mousePressed(int x, int y, int button) {
	if (leftArrowButton.inside(x, y) && page != 0) {
		countTweets = 0;
		page--;
	}
	else if (rightArrowButton.inside(x, y) && page != 9) {
		countTweets = 0;
		page++;
	}
	//these mouse clicks presses are for scrolling up and down
	if (state == "print") {
		if (upArrowButton.inside(x, y) || downArrowButton.inside(x, y)) {
			int leftOverTweets = results.size() - stop;
			if (downArrowButton.inside(x, y) /*and screen is not all the way up*/) {
				if (stop + 5 <= results.size()) {
					stop += 5;
					start += 5;
					printTweetInfo();
				}
				else if (leftOverTweets > 0) {
					start += 5;
					stop += results.size() % 5;
					printTweetInfo();
				}
			}
			if (upArrowButton.inside(x, y)) {//tweets shift up to show more tweets
				if (leftOverTweets == 0 && results.size() % 5 != 0) {
					start -= 5;
					stop -= results.size() % 5;
					printTweetInfo();
				}
				else if (start != 0) {
					start -= 5;
					stop -= 5;
					printTweetInfo();
				}

			}
		}
	}
	if (rightArrowButton.inside(x, y) || leftArrowButton.inside(x, y)) {
		if (page == 0) {
			tweetInfo.str("");
			tweetInfo << "The amount of tweets in the file are: " << tweets.size();
		}
		else if (page == 1) {

			queryHandler(true, "money");
		}
		else if (page == 2) {
			queryHandler(true, "politics");
		}
		else if (page == 3) {
			queryHandler(false, "Paris");
		}
		else if (page == 4) {
			queryHandler(false, "DreamWorks");
		}
		else if (page == 5) {
			queryHandler(false, "Uber");
		}
		else if (page == 6) {
			queryHandler(false, "Taylor Swift");
		}
		else if (page == 7) {
			queryHandler(true, "sandwich");
		}
		else if (page == 8) {
			queryHandler(true, "driving");
		}
		else if (page == 9) {
			queryHandler(false, "football");
		}
	}
}

//function to wrap words within a certain width
string ofApp::wrapString(string text, int width) {
	string typeWrapped = "";
	string tempString = "";
	vector <string> words = ofSplitString(text, " "); //create vector full of individual words in string passed in

	for (int i = 0; i < words.size(); i++) { //run through vector
		string wrd = words[i]; //get current word in vector

		// if we aren't on the first word, add a space
		if (i > 0) {
			tempString += " ";
		}
		tempString += wrd; //add current word to temp string

		int stringwidth = fontText.stringWidth(tempString); //set string width to length of line

		if (stringwidth >= width) {//check string with to add either space or new line before current word
			typeWrapped += "\n"; //if line is now longer than desired width add a new line
			tempString = wrd; // make sure we're including the extra word on the next line
		}
		else if (i > 0) {
			typeWrapped += " "; // if we aren't on the first word, add a space
		}
		typeWrapped += wrd; //add current word to string to be returned with new lines for wrapping
	}

	return typeWrapped;

}
//bool isCount? - does the query need to be printed or counted
void ofApp::queryHandler(bool isCount, string query) {
	tweetInfo.str("");
	if (isCount) {
		state = "count";
		// count the query number of times it's in tweets.getTweet()
		for (auto tweet : tweets) {
			if (tweet.getTweet().find(query) != string::npos) {
				countTweets++;
			}
		}
		outputCountedQuery(query);
	}
	else {
		state = "print";
		start = 0;
		stop = 5;
		results.clear();
		for (auto tweet : tweets) {
			if (tweet.getTweet().find(query) != string::npos) {
				results.push_back(tweet);
			}
			else {
				//no tweets matching query found
			}
		}
		printTweetInfo();
	}	
}

//this function is used to open the file and take the data
void ofApp::loadData() {
	inFile.open(ofToDataPath("sampleTweets.csv"));
	//checking if the file is open
	if (inFile.is_open()) {
		cout << "Reading data..." << endl;
		while (!inFile.eof()) {
			string date, time, tweet;
			getline(inFile, date, ' ');
			getline(inFile, time, ',');
			getline(inFile, tweet);
			Tweet newTweet(date, time, tweet);
			tweets.push_back(newTweet);			
		}
		//closing the file
		inFile.close();
		tweetInfo << "The amount of tweets in the file are: " << tweets.size();
	}

	else {
		cout << "Sorry, file isn't found" << endl;
	}
}

void ofApp::printTweetInfo() {
	tweetInfo.str("");
	for (int i = start; i < stop; i++) {
		tweetInfo << "Date: " << results[i].getDate();
		tweetInfo << " Time: " << results[i].getTime();
		tweetInfo << " Tweet: " << results[i].getTweet() << endl << endl;
	}
}

void ofApp::outputCountedQuery(string query) {
	tweetInfo << "The query, " << query << " appears in the file " << countTweets << " times. ";
}

void ofApp::instructionPanel() {
	int firstRectX = 530, secondRectX = 535, firstRectY = 700, secondRectY = 705, 
		firstRectHeight = 55, secondRectHeight = 45, fontY = 735, lineX = 870;
	//black outer borders
	ofSetColor(31, 27, 83);
	ofDrawRectRounded(firstRectX, firstRectY, 485, firstRectHeight, 7);
	ofDrawRectRounded(secondRectX, secondRectY, 480, secondRectHeight, 7);
	//grey box inside
	ofFill();
	ofSetColor(71, 60, 184);
	ofDrawRectRounded(secondRectX, secondRectY, 475, secondRectHeight, 7);
	//black box and inner black border
	ofSetColor(31, 27, 83);
	ofDrawRectRounded(firstRectX, firstRectY, 150, firstRectHeight, 7);
	ofDrawLine(lineX, 705, lineX, 755);
	ofSetLineWidth(5);
	
	//assigning white to the text
	ofSetColor(255);
	fontText.drawString("Controls:", 540, fontY);
	fontText.drawString("Pages", 785, fontY);
	//so the scrolling controls only shows when tweets are being printed
	if (state == "print") {
		fontText.drawString("Scrolling", 900, fontY);
		if (start != 0) {
		upArrowKey.draw(upArrowButton);
		}
		if (stop != results.size()) {
			downArrowKey.draw(downArrowButton);
		}
	}
	//importing the images(arrows) to show the controls
	if (page != 0) {
		leftArrowKey.draw(leftArrowButton);
	}
	if (page != 9) {
		rightArrowKey.draw(rightArrowButton);
	}
}