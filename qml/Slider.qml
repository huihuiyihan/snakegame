import QtQuick 2.1

Rectangle {
    id: root
    color: "transparent"
    radius: 5
    property alias value: grip.value
    property color fillColor: "#14aaff"
    property real gripSize: 40
    property real gripTolerance: 3.0
    property real increment: 0.1
    property bool enabled: true

    Rectangle {
        id: slider
        anchors {
            left: parent.left
            right: parent.right
            verticalCenter: parent.verticalCenter
        }
        height: 10
        color: "transparent"

        BorderImage {
           id: sliderbarimage
           source: "qrc:/images/Slider_bar.png"
           anchors { fill: parent; margins: 1 }
           border.right: 5
           border.left: 5
        }
        Rectangle {
            height: parent.height -2
            anchors.left: parent.left
            anchors.right: grip.horizontalCenter
            color: root.fillColor
            radius: 3
            border.width: 1
            border.color: Qt.darker(color, 1.3)
            opacity: 0.8
        }
        Rectangle {
            id: grip
            property real value: 0.5
            x: (value * parent.width) - width/2
            anchors.verticalCenter: parent.verticalCenter
            width: root.gripTolerance * root.gripSize
            height: width
            radius: width/2
            color: "transparent"

            Image {
                id: sliderhandleimage
                source: "qrc:/images/Slider_handle.png"
                anchors.centerIn: parent
            }

            MouseArea {
                id: mouseArea
                enabled: root.enabled
                anchors.fill:  parent
                drag {
                    target: grip
                    axis: Drag.XAxis
                    minimumX: -parent.width/2
                    maximumX: root.width - parent.width/2
                }
                onPositionChanged:  {
                    if (drag.active)
                        updatePosition()
                }
                onReleased: {
                    updatePosition()
                }
                function updatePosition() {
                    value = (grip.x + grip.width/2) / slider.width
                }
            }
        }

    }
}
