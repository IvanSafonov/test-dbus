# -*- coding: utf-8 -*-

import dbus
import gobject
import dbus.mainloop.glib

def hello_signal_handler(hello_string):
    print hello_string
    loop.quit()

dbus.mainloop.glib.DBusGMainLoop(set_as_default=True)
bus = dbus.SystemBus()
obj = bus.get_object("org.test.my","/")
obj.connect_to_signal("somethingHappened", hello_signal_handler, dbus_interface="org.test.my.Adaptor")

print obj.doSomething(-5, 10.64, dbus_interface = 'org.test.my.Adaptor')
loop = gobject.MainLoop()
gobject.timeout_add(10000, loop.quit)
loop.run()
