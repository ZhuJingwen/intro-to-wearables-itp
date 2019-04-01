// Copyright (c) 2018 p5ble
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

// The serviceUuid must match the serviceUuid of the device you would like to connect
const serviceUuid = "19b10010-e8f2-537e-4f6c-d104768a1214";
const characteristicsUUID = {
  button:"19b10013-e8f2-537e-4f6c-d104768a1214",
  sensor:"19b10012-e8f2-537e-4f6c-d104768a1214"
}
let buttonCharacteristic;
let sensorCharacteristic;
let buttonValue = 0;
let sensorValue = 0;
let myBLE;

function setup() {
  // Create a p5ble class
  myBLE = new p5ble();

  createCanvas(600, 400);
  colorMode(HSB, 255);
  background("#FFF");

  // Create a 'Connect and Start Notifications' button
  const connectButton = createButton('Connect and Start Notifications')
  connectButton.mousePressed(connectAndStartNotify);

  // // Create a 'Stop Notifications' button
  // const stopButton = createButton('Stop Notifications')
  // stopButton.mousePressed(stopNotifications);
}

function connectAndStartNotify() {
  // Connect to a device by passing the service UUID
  myBLE.connect(serviceUuid, gotCharacteristics);
}

// A function that will be called once got characteristics
function gotCharacteristics(error, characteristics) {
  if (error) console.log('error: ', error);
  console.log(characteristics[1].uuid);
  for(let i = 0; i < characteristics.length;i++){
    if(characteristics[i].uuid == characteristicsUUID.button){
      buttonCharacteristic = characteristics[i];
      myBLE.startNotifications(buttonCharacteristic, handleButton);
    }else if(characteristics[i].uuid == characteristicsUUID.sensor){
      sensorCharacteristic = characteristics[i];
      myBLE.startNotifications(sensorCharacteristic, handleSensor);

    }else{
      console.log("nothing");
    }
  }
  // Start notifications on the first characteristic by passing the characteristic
  // And a callback function to handle notifications
  

  // You can also pass in the dataType
  // Options: 'unit8', 'uint16', 'uint32', 'int8', 'int16', 'int32', 'float32', 'float64', 'string'
  // myBLE.startNotifications(myCharacteristic, handleNotifications, 'string');
}

// A function that will be called once got characteristics
function handleButton(data) {
  console.log('data: ', data);
  buttonValue = Number(data);
}

function handleSensor(data) {
  console.log('data: ', data);
  sensorValue = Number(data);
}

function draw() {
  noStroke();

  if(buttonValue>0){
    fill(color(200, 200, 200));
  }else{
    fill(color(100, 200, 200));

  }

  
  ellipse(sensorValue, 100, 20, 20);
}
