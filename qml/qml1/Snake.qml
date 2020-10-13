import QtQuick 2.4

Rectangle {
    id:snake;
    width: 20;
    height: 20;
    color:"red";
    x: 0.5 * areaX;
    y: 0.5 * areaY;

    property real areaX:500;
    property real areaY:500;
    readonly property int step: 10;
    readonly property int timeStep: 50;

    signal out;
    property int moveDirection:3; // 0,1,2,3,4 ; left ,right, up, down, death

    focus:true;
    Keys.onPressed: {
        if(event.key == Qt.Key_Left) {
            snake.moveDirection = 0;
            snake.start();
        }
        if(event.key == Qt.Key_Right) {
            snake.moveDirection = 1;
            snake.start();
        }
        if(event.key == Qt.Key_Up) {
            snake.moveDirection = 2;
            snake.start();
        }
        if(event.key == Qt.Key_Down) {
            snake.moveDirection = 3;
            snake.start();
        }
        event.accepted = true;
    }

    NumberAnimation on x { duration: snake.timeStep; }
    NumberAnimation on y { duration: snake.timeStep; }

    function start(){
        if(!time.running) {
            time.running = true;
            snake.x = 0.5 * areaX;
            snake.y = 0.5 * areaY;
            snake.color = "red";
        }
    }

    function stop() { time.running = false; }

    function move(){
        switch(moveDirection)
        {
        case 0:         /*left */
            snake.x -= snake.step;
            break;
        case 1:         /*right*/
            snake.x += snake.step;
            break;
        case 2:         /*up*/
            snake.y -= snake.step;
            break;
        case 3:         /*down*/
            snake.y += snake.step;
            break;
        case 4:         /*death*/
            snake.y = 0;
            snake.x = 0;
            break;
        default:        /*death*/
            snake.y = 0;
            snake.x = 0;
            break;
        }
        checkOut();
    }

    function checkOut(){
        if(snake.x < 0 || snake.y < 0 || (snake.x+snake.width) > areaX  || (snake.y+snake.height) > areaY ) {
            out();
            return true;
        } else {
            return false;
        }
    }

    Timer{
        id:time;
        interval:snake.timeStep;
        repeat:true;
        onTriggered : move();
    }

    onOut: {
        snake.stop();
        snake.moveDirection = 4;
        snake.color = "black";
    }
}
