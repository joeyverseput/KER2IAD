#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
    
        ofSoundPlayer voicePlayer[6];
        bool playing[1];
    
    private:
        ofArduino arduino;
    
        void setupArduino(const int& version);
    
        void digitalPinChanged (const int& pin);
    
        void analogPinChanged (const int& pin);
};
