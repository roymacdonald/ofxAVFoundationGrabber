#pragma once

#include "ofMain.h"
#include "ofxVideoGrabber.h"

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		

		void keyPressed(int key) override;
		
    
    ofxVideoGrabber vidGrabber;
    
		
};
