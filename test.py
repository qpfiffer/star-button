#!/usr/bin/env python

#import gtk
#
#w = gtk.Window(gtk.WINDOW_TOPLEVEL)
#w.set_decorated(False)
#
#b = gtk.Button("Hello World")
#w.add(b)
#
#b.show()
#w.show()
#
#gtk.main()

WIDTH = 550
HEIGHT = 460


import gtk, cairo, math

class PyApp(gtk.Window):

    def __init__(self):
        super(PyApp, self).__init__(gtk.WINDOW_TOPLEVEL)

        self.set_decorated(False)
        self.set_size_request(WIDTH, HEIGHT)
        self.set_position(gtk.WINDOW_TOPLEVEL)
        self.set_app_paintable(True)

        screen = self.get_screen()
        rgba = screen.get_rgba_colormap()
        self.set_colormap(rgba)

        self.connect("destroy", gtk.main_quit)

        darea = gtk.DrawingArea()
        darea.connect("expose-event", self.expose)
        self.add(darea)

        self.show_all()

    def expose(self, widget, event):
        cr = widget.window.cairo_create()

        # Sets the operator to clear which deletes everything below where an object is drawn
        cr.set_operator(cairo.OPERATOR_CLEAR)
        # Makes the mask fill the entire window
        cr.rectangle(0.0, 0.0, WIDTH, HEIGHT)
        # Deletes everything in the window (since the compositing operator is clear and mask fills the entire window
        cr.fill()
        # Set the compositing operator back to the default
        cr.set_operator(cairo.OPERATOR_OVER)

        # Draw a fancy little circle for demonstration purpose
        cr.set_source_rgba(0.5,1.0,0.0,1)
        image = cairo.ImageSurface.create_from_png("./star.png")

        cr.set_source_surface(image)
        cr.paint()

PyApp()
gtk.main()
