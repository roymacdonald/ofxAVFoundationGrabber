
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    
    
    gui.setup("VideoGrabber", "settings.json");
    gui.setPosition(20,20);
    
    uidDropdown =  make_unique<ofxDropdown>(selectedUid);
    uidDropdown->disableMultipleSelection();
    uidDropdown->enableCollapseOnSelection();


    //get back a list of devices.
    vector<ofVideoDevice> devices = vidGrabber.listDevices();

    for(size_t i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            uidDropdown->add( devices[i].serialID, devices[i].deviceName + " _ " + devices[i].serialID);
        }
    }
        
    
    gui.add(uidDropdown.get());
   

    // this goes before loading the gui, so if it actually loads ofApp::selectedCameraChanged will get called.
    uidListener = selectedUid.newListener(this, &ofApp::selectedCameraChanged);
    
    if(ofFile::doesFileExist("settings.json")){
        gui.loadFromFile("settings.json");
    }
    
    
//    vidGrabber.setDesiredFrameRate(30);
    vidGrabber.setup(camWidth, camHeight);

}

//--------------------------------------------------------------
void ofApp::selectedCameraChanged(string &){
    vidGrabber.close();
    vidGrabber.setUniqueID(selectedUid);
    vidGrabber.setup(camWidth, camHeight);
}
//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(100, 100, 100);
    vidGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0xffffff);
    vidGrabber.draw(20, 20);
    
    gui.draw();
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'g'){
        bDrawGui ^= true;
    }
}

