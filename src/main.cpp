#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	//prevents the window being resized
	ofGLFWWindowSettings settings;
	settings.resizable = false;
	settings.setSize(1024, 768);
	ofCreateWindow(settings);

	ofRunApp(new ofApp());

}
