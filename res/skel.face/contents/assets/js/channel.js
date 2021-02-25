'use strict';
var wsUri = "ws://127.0.0.1:12345";
window.loggedin = false;

window.onload = function()
{
    var socket = new WebSocket(wsUri);

    socket.onclose = function()
    {
        MereConnect.isReady = false;
        console.error("web channel closed");
        alert("Something went wrong - connection to MERE Connect closed. \nPlease check if MERE Connect is running!");
    };
    socket.onerror = function(error)
    {
        MereConnect.isReady = false;
        console.error("web channel error: " + error);
        alert("Something went wrong - unable to connect to MERE Connect. \nPlease check if MERE Connect is running!");
    };
    socket.onopen = function()
    {
        // alert(QWebChannel)
        window.channel = new QWebChannel(socket, function(channel)
        {
            //connect to the changed signal of a property
            channel.objects.MereConnect.userListChanged.connect(function() {
                $('#userlist').empty();
                //access the property
                channel.objects.MereConnect.userList.forEach(function(user) {
                    $('#userlist').append(user + '<br>');
                });
            });
            //connect to a signal
            channel.objects.MereConnect.newMessage.connect(function(time, user, message) {
                $('#chat').append("[" + time + "] " + user + ": " +  message + '<br>');
            });
            //connect to a signal
            channel.objects.MereConnect.keepAlive.connect(function(args) {
                if(window.loggedin) {
                    //call a method
                    channel.objects.chatserver.keepAliveResponse($('#loginname').val())
                    console.log("sent alive");
                }
            });

            MereConnect.isReady = true;
        });
    }
}
