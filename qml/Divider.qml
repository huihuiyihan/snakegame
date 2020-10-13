import QtQuick 2.1

Rectangle {
    id: root
    anchors.fill: parent
    color: "transparent"
    property alias radiusParent:slider.radiusParent
    property alias value: slider.value
    property alias valueY: slider.valueY
    property alias lineWidth: line.width
    property alias gripSize: slider.gripSize

    Rectangle {
        id: line
        anchors { top: parent.top; bottom: parent.bottom }
        x: parent.value * parent.width - (width / 2)
        width: 2
        color: "lightgray"
    }
    Rectangle {
        id: lineY
        anchors { left: parent.left; right: parent.right }
        y: parent.valueY * parent.height - (height / 2)
        height: 2
        color: "lightgray"
    }
    // bottomgrip
    Curtain {
        id: slider
        increment: 0.0
        anchors {
//            bottomMargin: (gripSize / 2) + 5
            left: parent.left
            right: parent.right
        }
        imageSource: "qrc:/images/Triangle_bottom.png"
        //onValueChanged: slider.value = slider2.value

    }
}
