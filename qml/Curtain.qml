
import QtQuick 2.0

Rectangle {
    id: root

    property alias value: grip.value
    property alias valueY: grip.valueY
    property alias rota: grip.rota
    property color gripColor: "transparent"
    property real gripSize: 20
    property real gripTolerance: 2.5
    property real increment: 0.1
    property var radiusParent: 50
    property bool enabled: true
    property string imageSource: "qrc:/images/Triangle_Top.png"

    Rectangle {
        id: grip
        property real value: 0.5
        property real valueY: 0.5
        property real rota: 0
        x: (value * parent.width) - width/2
        y: root.parent.height/2 - height/2;

//        anchors.verticalCenter: parent.verticalCenter
        width: root.gripTolerance * root.gripSize
        height: width
//        radius: width/2
        color: "blue"

        Image {
            id: sliderhandleimage
            source: imageSource
            anchors.centerIn: parent
            rotation: grip.rota
        }

        MouseArea {
            id: mouseArea
            enabled: root.enabled
            anchors.fill:  parent
            drag {
                target: grip
                axis: Drag.XandYAxis
                minimumX: 0
                maximumX: root.width - parent.width
                minimumY: 0
                maximumY: root.parent.height - parent.height

            }
            onPositionChanged:  {
                if (drag.active)
                    updatePosition()
            }
            onReleased: {
                updatePosition()
            }
            function updatePosition() {
                value = (grip.x + grip.width/2) / grip.parent.width
                valueY = (grip.y + grip.height/2) / root.parent.height
                rota = 450-Math.atan(valueY/value)/(Math.PI/180);
                console.log("value:"+value+"-valueY:"+valueY+"-r:"+rota);
                var a1 = Math.cos(rota) * radiusParent;
                var b1 = Math.sin(rota) * radiusParent;

            }
        }
    }
}
