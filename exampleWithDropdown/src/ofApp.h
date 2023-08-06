#pragma once

#include "ofMain.h"
#include "ofxVideoGrabber.h"

#include "ofxGui.h"
#include "ofxDropdown.h"

class ofApp : public ofBaseApp{

    public:
        void setup() override;
        void update() override;
        void draw() override;
        

        void keyPressed(int key) override;
        
    
    ofxVideoGrabber vidGrabber;
    
    
    ofxPanel gui;
    
    ofParameter<string> selectedUid = {"Selected Video Grabber", ""};
    

    unique_ptr<ofxDropdown> uidDropdown;
    
    ofEventListener uidListener;
    void selectedCameraChanged(string &);
    
    
    int camWidth = 1280;
    int camHeight = 720;
    
    bool bDrawGui = true;
    
};
