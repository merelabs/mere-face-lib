function run(event, value)
{
    if(event.keyCode === 13)
    {
        var process = MereConnect.Components.get("system/msIProcess");
        process.setName(value);
        process.run();
        return false;
    }

    return true;
}
