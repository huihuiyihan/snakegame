import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.0
import Qt.labs.settings 1.0
import QtQuick.Dialogs 1.1

Rectangle{
    id:root

    property var vm: msg
//    property int mColumns: root.width/16
//    property int mRows: root.height/16
//    property int punkte: 0
//    property int gesch: 0
//    property color defaultSnakeColor: "white";
//    property int colorCaller: -1;
//    property color defaultFoodColor: "red"
//    property color backgroundColor: "DarkBlue";
//    property color defaultDrawbackColor: "brown";

//    property color nocolor:"green";
//    property int difficulty: 0

//    property int recangleSize: 16;
    signal newFoodCreated;

    Component.onCompleted: {

        newFoodCreated.connect(newCandy);
        console.log(JSON.stringify(vm.food))
    }

    Rectangle {
        id:snake;
        width: 20;
        height: 20;
        color:"red";
        x: vm.snake.headx;
        y: vm.snake.heady;

        property real areaX:500;
        property real areaY:500;
        readonly property int step: 10;
        readonly property int timeStep: 50;

        signal out;
        property int moveDirection:3; // 0,1,2,3,4 ; left ,right, up, down, death

        NumberAnimation on x { duration: snake.timeStep; }
        NumberAnimation on y { duration: snake.timeStep; }

        onOut: {
            snake.color = "black";
        }
    }
    Rectangle {
        id:candy;
        width: 20;
        height: 20;
        signal ate; // 被吃时发信号

        x:vm.food.foodx
        y:vm.food.foody
        color:Qt.rgba(Math.random(),Math.random(),Math.random(),1);


        NumberAnimation on x { duration: 50; }
        NumberAnimation on y { duration: 50; }

        onAte:{
            console.log("has eat one x:"+candy.x +"-y:"+candy.y);

            candy.opacity = 0;
        }

    }
    function newCandy(x, y){
        candy.opacity = 1;
        console.log("create new one x:"+candy.x +"-y:"+candy.y);

    }
    Connections{
        target: vm
        onFoodEat:{
            candy.ate();
        }
    }

    //GameQML{}

}
