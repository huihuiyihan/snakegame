import QtQuick 2.4

Rectangle {
    id:gameView;
    width: 500;
    height: 500;
    property int score:0;

    Text{
        anchors.centerIn: parent;
        text:"score: "+ gameView.score;
    }

    Snake{
        id:snake;
        areaX : 500;
        areaY : 500;
        onOut:{
            gameView.score = 0;
        }
    }

    Candy { id:candy; }

    Timer{
        id:time;
        interval:10;
        repeat:true;
        running:true;
        onTriggered: {
            if(collide(snake,candy)) {
                candy.ate(); // signal;
                ++gameView.score;
                candy.newCandy();
            }
        }
    }

    // to check two rectangles collided 碰撞
    function collide(item1,item2) {
        if( ((item1.y+item1.height) >= item2.y)
                && (item1.y <=( item2.y+item2.height)) ) {
            if( ((item1.x+item1.width) >= item2.x)
                    && (item1.x <=( item2.x+item2.width)) ) {
                return true;
            }
            return false;
        }
        return false;
    }
}
