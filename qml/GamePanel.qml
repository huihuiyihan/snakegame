import QtQuick 2.1
import QtQuick.Controls 2.4
import QtQuick.Window 2.1

ApplicationWindow {
    id:winRoot
    title: qsTr("Hello World")
    visible: true
    visibility: "Maximized"

    property var vm: msg

    Rectangle {
        id: root
        color: "black"
        anchors.fill: parent
        property int pixDens: Math.ceil(Screen.pixelDensity)
        property int itemWidth: 25 * pixDens
        property int itemHeight: 10 * pixDens
        property int windowWidth: Screen.desktopAvailableWidth
        property int windowHeight: Screen.desktopAvailableHeight
        property int scaledMargin: 2 * pixDens
        property int fontSize: 5 * pixDens

        focus:true;
        Keys.onPressed: {
            if(event.key == Qt.Key_Left) {
                console.log("keyleft")
                vm.turn(0);
                //snake.setSnakeHeight(0);
            }
            if(event.key == Qt.Key_Right) {
                vm.turn(1);
                //snake.setSnakeHeight(1);
            }
            if(event.key == Qt.Key_Up) {
                vm.turn(2);
                //snake.setSnakeHeight(2);
            }
            if(event.key == Qt.Key_Down) {
                vm.turn(3);
                //snake.setSnakeHeight(3);
            }
            event.accepted = true;
        }

        QtObject {
            id: d
            property real gripSize: 20
        }

        ContentPanel {
            id: content
            color: "lightblue"
            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
                bottom: parameterPanel.top
            }
            //gripSize: d.gripSize
            Component.onCompleted: {
                console.log("ContentPanel-"+content.width);
            }
        }

        ContorlPanel {
            id: parameterPanel

            score:msg.punkte
            color: "orange"
            anchors {
                left: parent.left
                right: effectName.left
                bottom: parent.bottom
                margins: root.scaledMargin
                leftMargin: root.scaledMargin + root.itemHeight
            }
            gripSize: d.gripSize
            height: root.itemHeight * 3.5
            onMovedir:{
                vm.turn(dire);
            }
        }
        Connections{
            target: msg
            onFoodChanged:
            {
                content.newFoodCreated(food.foodx, food.foody);
            }

        }

        Button {
            id: effectName
            anchors {
                right: parent.right
                bottom: perfHolder.top
                margins: root.scaledMargin
            }

            text: "Start"
            width: root.itemWidth * 2
            height:  root.itemHeight * 1.5
            onClicked: {
                msg.start(content.width,content.height);
                //effectName.visible = false
//                listview.visible = true

            }
            //color: "#303030"
        }

        Rectangle {
            id: perfHolder
            color: "yellow"
            anchors {
                right: parent.right
                bottom: parent.bottom
                margins: root.scaledMargin
            }
            height: root.itemHeight * 1.5
            width: root.itemWidth * 2

        }



    }



}
