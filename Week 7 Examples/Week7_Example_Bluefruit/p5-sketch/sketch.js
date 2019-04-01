// Copyright (c) 2018 p5ble
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

// The serviceUuid must match the serviceUuid of the device you would like to connect


const serviceUuid = "6e400001-b5a3-f393-e0a9-e50e24dcca9e";
const txCharacteristic = "6e400002-b5a3-f393-e0a9-e50e24dcca9e"; // transmit is from the phone's perspective
const rxCharacteristic = "6e400003-b5a3-f393-e0a9-e50e24dcca9e";  // receive is from the phone's perspective

let myCharacteristic;
let myValue = 0;
let myBLE;

function setup() {
  // Create a p5ble class
  myBLE = new p5ble();

  createCanvas(200, 200);
  textSize(20);
  textAlign(CENTER, CENTER);

  // Create a 'Connect and Start Notifications' button
  const connectButton = createButton('Connect and Start Notifications')
  connectButton.mousePressed(connectAndStartNotify);

  // Create a 'Stop Notifications' button
  const stopButton = createButton('Stop Notifications')
  stopButton.mousePressed(stopNotifications);
}

function connectAndStartNotify() {
  // Connect to a device by passing the service UUID
  myBLE.connect(serviceUuid, gotCharacteristics);
}

// A function that will be called once got characteristics
function gotCharacteristics(error, characteristics) {
  if (error) console.log('error: ', error);
  for(let i = 0; i < characteristics.length; i++){
   if(rxCharacteristic ==characteristics[i].uuid){
    myCharacteristic = characteristics[i];
    myBLE.startNotifications(myCharacteristic, handleNotifications);
   } 
  }
 
  // Start notifications on the first characteristic by passing the characteristic
  // And a callback function to handle notifications
  //myBLE.startNotifications(myCharacteristic, handleNotifications);
  // You can also pass in the dataType
  // Options: 'unit8', 'uint16', 'uint32', 'int8', 'int16', 'int32', 'float32', 'float64', 'string'
  // myBLE.startNotifications(myCharacteristic, handleNotifications, 'string');
}

// A function that will be called once got characteristics
function handleNotifications(data) {
  console.log('data: ', data);
  myValue = data;
}

// A function to stop notifications
function stopNotifications() {
  myBLE.stopNotifications(myCharacteristic);
}

function draw() {
  background(250);
  // Write value on the canvas
  text(myValue, 100, 100);
}
