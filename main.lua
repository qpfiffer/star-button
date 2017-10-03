function love.load(arg)
    star_image = love.graphics.newImage("star.png")

    love.window.close()

    event_file = io.open("/dev/input/event7", "rb")
    io.input(event_file)
end

function love.conf(t)
    t.console = true
end

function love.update(dt)
    local data = io.read(0)
    if data == "" then
        local good_data = io.read(64)
        --print("We have data! " .. good_data)
        key_has_been_pressed = true
        love.window.setMode(600, 400, {borderless=true})
    end
end

function love.draw(dt)
    if key_has_been_pressed then
        love.graphics.draw(star_image, 0, 0)
    end
end
