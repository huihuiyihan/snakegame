import QtQuick 2.0

Rectangle {
    id:candy;
    width: 20;
    height: 20;
    signal ate; // 被吃时发信号

    x:Math.random() * 500;
    y : Math.random() * 500;
    color:Qt.rgba(Math.random(),Math.random(),Math.random(),1);

    function newCandy(){
        candy.x = Math.random() * 500;
        candy.y = Math.random() * 500;
        candy.color = Qt.rgba(Math.random(),Math.random(),Math.random(),1);
        candy.opacity = 1;
    }

    NumberAnimation on x { duration: 50; }
    NumberAnimation on y { duration: 50; }

    onAte:candy.opacity = 0;
}
