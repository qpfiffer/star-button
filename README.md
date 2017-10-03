A stupid project that shows you a star when you hit the star button on the new
thinkpads.

You'll need Love2D. You'll also need to make sure that your user is in whatever
group the `/dev/input/event*` meta-files are in. You can check with `ls -al`:

```
total 0
drwxr-xr-x  4 root root     460 Oct  3 12:58 .
drwxr-xr-x 21 root root    4220 Oct  3 12:58 ..
drwxr-xr-x  2 root root      60 Oct  3 12:58 by-id
drwxr-xr-x  2 root root     180 Oct  3 12:58 by-path
crw-rw----  1 root input 13, 64 Oct  3 12:58 event0
crw-rw----  1 root input 13, 65 Oct  3 12:58 event1
crw-rw----  1 root input 13, 74 Oct  3 12:58 event10
crw-rw----  1 root input 13, 75 Oct  3 12:58 event11
crw-rw----  1 root input 13, 76 Oct  3 12:58 event12
crw-rw----  1 root input 13, 77 Oct  3 12:58 event13
crw-rw----  1 root input 13, 78 Oct  3 12:58 event14
crw-rw----  1 root input 13, 79 Oct  3 12:58 event15
crw-rw----  1 root input 13, 66 Oct  3 12:58 event2
crw-rw----  1 root input 13, 67 Oct  3 12:58 event3
crw-rw----  1 root input 13, 68 Oct  3 12:58 event4
crw-rw----  1 root input 13, 69 Oct  3 12:58 event5
crw-rw----  1 root input 13, 70 Oct  3 12:58 event6
crw-rw----  1 root input 13, 71 Oct  3 12:58 event7
crw-rw----  1 root input 13, 72 Oct  3 12:58 event8
crw-rw----  1 root input 13, 73 Oct  3 12:58 event9
crw-rw----  1 root input 13, 63 Oct  3 12:58 mice
crw-rw----  1 root input 13, 32 Oct  3 12:58 mouse0
crw-rw----  1 root input 13, 33 Oct  3 12:58 mouse1
```

It's input on my system.

After you've got all that taken care of you can run the program with:

```
love .
```
