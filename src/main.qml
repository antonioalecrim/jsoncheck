import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("JSON Check")
    width: 740
    height: 480
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: fileDialog.open()
                shortcut: StandardKey.Open
            }
            MenuItem {
                text: qsTr("&Clear")
                onTriggered: { mainText.cursorPosition = 0; mainText.text = ""; }
                shortcut: StandardKey.Refresh
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
                shortcut: StandardKey.Close
            }
        }
    }

    TextArea {
        id: mainText
        anchors.fill: parent
    }

    property url iUrl
    FileDialog {
        id: fileDialog
        selectMultiple: true
        title: "Please choose a file"
        nameFilters: [ "json files (*.json)", "All files (*)" ]
        onAccepted: {
            for (var i= 0; i < fileUrls.length; i++) {
                iUrl = fileUrls[i]
                mainText.text += checker.checkJsonFile(iUrl)+"\n"
            }
        }
    }
}
