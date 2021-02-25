var MereConnect = (function () {
    var _components = {
        "system" : {
            "msIProcess" : "MereProcess"
        }
    }

    this.isReady = false;

    this.Components = (function () {
        this.get = function(compoenent){

            var connect = "MereProcess";
            return window.channel.objects[connect];
        }

        return this;
    })();

    return this;
})();
