#include "ofApp.h"
#include "ShapeBox.h"
#include "WindowBoard.h"
#include "iostream"

//--------------------------------------------------------------
void ofApp::setup()
{
    
    ofSetBackgroundColor(30,30,30);
    ofSetColor(255,255,255, 100);    // white, 100/255 transparent
    

    b.settings(40, 40);
 
    // open port by number (you may need to change this)
    midiIn.openPort(1);
    //midiIn.openPort("IAC Pure Data In");	// by name
    //midiIn.openVirtualPort("ofxMidiIn Input"); // open a virtual port
    
    // don't ignore sysex, timing, & active sense messages,
    // these are ignored by default
    midiIn.ignoreTypes(false, false, false);
    
    // add ofApp as a listener
//    midiIn.addListener(this);
    
    // print received messages to the console
    midiIn.setVerbose(true);



}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    b.drawShapesOntoBoard();
//    b.drawShapesOntoBoard(Shape x);

}


//--------------------------------------------------------------
void ofApp::exit() {
    
    // clean up
    midiIn.closePort();
 //   midiIn.removeListener(this);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch(key)
    {
        case 'l':
            midiIn.listPorts();
            break;
        case ' ':
            b.settings(200, 200);
            std::cout << "wahoooo" << endl;
            break;
        case 'b':
             ofSetColor(255,0,0);    // red
            break;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    b.settings(40, 40);

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

