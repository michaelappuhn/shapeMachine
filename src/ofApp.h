#pragma once

#include "ofMain.h"
#include "WindowBoard.h"
#include "ofxMidi.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    	void exit();
    

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        Board b;
    
    
        // Adding here that you have to manually add "CoreMidi" to the "Build Libraries" before oFxMidi works
        // http://forum.openframeworks.cc/t/ofxmidi-updates/2435/125
        // http://stackoverflow.com/questions/3352664/how-to-add-existing-frameworks-in-xcode-4
        // https://developer.apple.com/library/ios/recipes/xcode_help-project_editor/Articles/AddingaLibrarytoaTarget.html#//apple_ref/doc/uid/TP40010155-CH17-SW1
    
        ofxMidiIn midiIn;
//      ofxMidiMessage midiMessage;

		
};
