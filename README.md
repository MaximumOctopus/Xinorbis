A C++ rewrite of Xinorbis is currently in progress. Beta version due Summer/Autumn 2026.

I'll be uploading the code regularly (at least once a week) as I work through the rewrite/remaster.

I'm adding raw functionality first, then once that's working, I'll start tidying and adding the remainder of the missing features.

I don't expect a feature-complete version until the end of 2026. There won't be a stable release until around August/September, but as of late June some functionality is available (though it's going to be buggy and missing major functions for a while...).

There's over 45k lines of code to rewrite (and I'm redesigning a lot of the logic), so it'll take some time.

Database functions are not going to be part of the initial release.

2026/08/16

I think all of the original code (except for the database (folder history) stuff and a few other small random things) has now been rewritten in C++. The CategoryBar replacement has also been written (it's called XIceCream and it looks great). I put together a new to-do list of 88 items, which is now <20 (though most of these are grid- or folder history-related).

Although the code is written, there are still holes in the logic regarding updating the UI (etc.) because I've altered the way a lot of this works (or removed it entirely so I can rewrite it as I test) and I'm planning on making a lot more changes. 

I'm going to spend the next week or two testing and bug fixing. See you soon!

2026/08/07

Most of the original Delphi code has been rewritten in C++ (excluding the Folder History database functions, but they're going to be based on the FolderScanUltra code). There are still a few functions and dialogs to finish, but the majority of stage 1 is done.

In the last few days I've cut down my informal "to do" list from 161 to 18. But this is not the full picture of what's left!!!

I'm now going to concentrate on one part at a time, starting with FrameSummary and then the FrameProperties display (one of the core parts of the application).

2026/07/26

Still making good progress through the code, but still a few thousand lines of code to rewrite (and much to add). I've rewritten the scan and report engines, and there are still things I want to refactor, but this will come later.

A few more menus and forms are working, but I'm going to leave testing until I have more of the code rewritten (there's not point testing at the moment as although the code is rewritten, the forms and code aren't fully connected to each other).

The GUI will take a lot of time to finalise as the previous version(s) used several commercial components that are not availble in my open source remake. Advanced String Grids and the TMS CategoryBar are the most important missing components. I will be able to add most of the important grid functionality to the default C++ Builder VCL grid, but I'm going to write my own CategoryBar (called IceCream in the code, as it reminds me of a neopolitan ice cream :).

2026/07/12

A lot of changes since the last update. Many of the Report-based forms and code are converted, though not finished. Much of the code behind the analysis displays has been rewritten but remains untested and not yet connected to the Propeties Frame. Still a long way away from a stable build, but getting closer each day. I'm starting to connect up the main menu and popup menus, but many remain untouched.

2026/07/04

We have some very, very basic functionality. There is a *lot* of code left to rewrite and a lot of "to do" comments where I've rewritten the majority but there's still some code to add. I have done very little testing.

PAF
