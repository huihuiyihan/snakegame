
import QtQuick 2.0

Rectangle {
    id: root
    color: "orange"
    height: view.model.count * sliderHeight
    property color lineColor: "black"
    property real gripSize: 25
    property real spacing: 20
    property real sliderHeight: 60

    property ListModel model: ListModel { }

    property int score:0;

    signal movedir(var dire)

    Rectangle {
        id:tool
        color: "green"
        radius: width/2
        width: height
        height: parent.height
        Divider {
            id: divider
            radiusParent:width
            z: 1.0
            onValueChanged: {
                updateDivider(divider.value,divider.valueY)
            }
        }
    }

    Rectangle {
        id:score
        color: "lightgray"
        width: height
        anchors.left: tool.right
        height: parent.height
        Text{
            anchors.centerIn: parent;
            text:"score: "+ root.score;
        }
    }

    function updateDivider(w,h){
        var cx = tool.width/2;
        var cy = tool.height/2;
        var x = w*tool.width;
        var y = h*tool.height;
        if(x < cx && y < cy){
            movedir(0);
        } else if(x > cx && y < cy){
            movedir(1);
        } else if(x < cx && y > cy){
            movedir(2);
        } else if(x > cx && y > cy){
            movedir(3);
        }
    }

    //    Component {
    //        id: editDelegate

    //        Rectangle {
    //            id: delegate
    //            width: parent.width
    //            height: root.sliderHeight
    //            color: "transparent"

    //            Text {
    //                id: text
    //                text: name
    //                color: "white"
    //                anchors {
    //                    top: parent.top
    //                    bottom: parent.bottom
    //                    left: parent.left
    //                }
    //                font.pixelSize: fontSize
    //                horizontalAlignment: Text.AlignRight
    //                verticalAlignment: Text.AlignVCenter
    //                width: 8 * fontSize
    //            }

    //            Slider {
    //                anchors {
    //                    top: parent.top
    //                    bottom: parent.bottom
    //                    left: text.right
    //                    leftMargin: 20
    //                    right: parent.right
    //                    rightMargin: 20
    //                }
    //                gripSize: root.gripSize
    //                value: model.value
    //                onValueChanged: view.model.setProperty(index, "value", value)
    //            }
    //        }
    //    }

    //    ListView {
    //        id: view
    //        anchors.fill: parent
    //        model: root.model
    //        delegate: editDelegate
    //        interactive: false
    //    }
}
