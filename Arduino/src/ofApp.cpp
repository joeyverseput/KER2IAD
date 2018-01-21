#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
    
    arduino.connect("/dev/cu.usbmodem1411");
    arduino.sendFirmwareVersionRequest();
    
    for (int i = 0; i < 1; i++) {
    voicePlayer[1].load(ofToDataPath("a.mp3"));
    voicePlayer[1].setLoop(true);
    voicePlayer[1].play();
    voicePlayer[1].setPaused(true);
        
    voicePlayer[2].load(ofToDataPath("b.mp3"));
    voicePlayer[2].setLoop(true);
    voicePlayer[2].play();
    voicePlayer[2].setPaused(true);
        
    ofSoundSetVolume(0.2);
        
    //voicePlayer[3].load(ofToDataPath("falsemusic.mp3"));
    //voicePlayer[3].setLoop(true);
    //voicePlayer[3].play();
    //voicePlayer[3].setPaused(true);
        
    //voicePlayer[4].load(ofToDataPath("music.mp3"));
    //voicePlayer[4].setLoop(true);
    //voicePlayer[4].play();
    //voicePlayer[4].setPaused(true);
    //ofSoundSetVolume(0.1);
        
    //voicePlayer[5].load(ofToDataPath("falsemusic.mp3"));
    //voicePlayer[5].setLoop(true);
    //voicePlayer[5].play();
    //voicePlayer[5].setPaused(true);
    //ofSoundSetVolume(0.5);
        
    //voicePlayer[6].load(ofToDataPath("music.mp3"));
    //voicePlayer[6].setLoop(true);
    //voicePlayer[6].play();
    //voicePlayer[6].setPaused(true);
    //ofSoundSetVolume(0.5);
    }

    
    
    //ofSoundSetVolume(0.2);

}

//--------------------------------------------------------------
void ofApp::update(){
    arduino.update();
    
    //ofSoundUpdate();
    //float time = ofGetElapsedTimef();
    //float x = time* 0.1f + 30;
    //for (int i = 0; i< 4; i++) {
        //float y = i * 0.02f;
        //float volume = ofNoise(x, y);
        //voicePlayer[i].setVolume(volume);
        //voicePlayer[i].setSpeed(volume);
    //}
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //for(int i = 0 ; i < 4; i++) {
        //ofSetColor(i * 20 + 128, i * 80, i * 10 + 60);
        //ofDrawRectangle(100, i * 30 + 200, voicePlayer[i].getVolume() * 300, 5);
    //}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    arduino.sendDigital(11, ARD_HIGH);
    
    //if (key== '1') {
        //playing[0] = !playing[0];
        //voicePlayer[0].setPaused(playing[0]);
    //}
    //if (key== '2') {
        //playing[1] = !playing[1];
        //voicePlayer[1].setPaused(playing[1]);
    //}
    //if (key== '3') {
        //playing[2] = !playing[2];
        //voicePlayer[2].setPaused(playing[2]);
    //}
    //if (key== '4') {
        //playing[3] = !playing[3];
        //voicePlayer[3].setPaused(playing[3]);
    //}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    arduino.sendDigital(11, ARD_LOW);
}

//--------------------------------------------------------------
void ofApp::setupArduino(const int& version) {
    ofLog() << "Arduino firmware found" << arduino.getFirmwareName() << arduino.getMajorFirmwareVersion() << arduino.getMinorFirmwareVersion() << endl;
    
    arduino.sendDigitalPinMode(11, ARD_OUTPUT);
    arduino.sendDigitalPinMode(12, ARD_INPUT);
    arduino.sendAnalogPinReporting(0, ARD_ANALOG);
    arduino.sendAnalogPinReporting(1, ARD_ANALOG);
    arduino.sendAnalogPinReporting(2, ARD_ANALOG);
    
    ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
    ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    
}

void ofApp::analogPinChanged(const int& pin) {
    ofLog() << "Analog pin" << pin << " value: " << arduino.getAnalog(pin) << endl;
    
    if (arduino.getAnalog(0) < 600 or arduino.getAnalog(1) < 600 or arduino.getAnalog(2) < 600) {
        voicePlayer[1].setPaused(false);
    } else {
        voicePlayer[1].setPaused(true);
    }
    
    if (arduino.getAnalog(0) > 600 and arduino.getAnalog(1) > 600 and arduino.getAnalog(2) > 600) {
        voicePlayer[2].setPaused(false);
    } else {
        voicePlayer[2].setPaused(true);
    }
}

void ofApp::digitalPinChanged(const int& pin) {
}
