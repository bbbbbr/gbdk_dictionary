A simple dictionary word validator for use with GBDK / ZGB / GBStudio which supports ROM banking.

At present it's a quick and simple implementation with support for words 3-6 letters long. 
While not as fast and size efficient as the [GB-wordyl](https://github.com/bbbbbr/gb-wordyl) 
dictionary, it's far less complicated and should be easier to understand, modify and use in other projects.

There is lookup function code duplication in the banked sources as a result of trying to use as little
Bank 0 space as possible, since that space is sometimes in short very supply in GBStudio projects using
plugins.

### GB Studio example project
[Shane McCafferty / EGVroom](https://x.com/EGVroom) provided an example GBStudio project (under [GBStudioLookUpDemo](GBStudioLookUpDemo) showing how to interface with and use the dictionary. A pre-built example ROM is included in the project under [GBStudioLookUpDemo/build/rom](GBStudioLookUpDemo/build/rom).

In this project there are variables $Selection1 .. $Selection6 which store numbers (1-26) representing alphabet letters (a-z).

### Plugin
[Pautomas](https://github.com/pau-tomas) packaged the dictionary as a plugin so it's easier to integrate with GBStudio: 
[GBStudioLookUpDemo/plugins/Dictionary](GBStudioLookUpDemo/plugins/Dictionary)

Use the `If is valid word` event to check a word. It calls `isThisAWord()` in [native_testfunc.c](GBStudioLookUpDemo/plugins/Dictionary/engine/src/data/native_testfunc.c)

To install the plugin copy the contents of the [plugins directory](GBStudioLookUpDemo/plugins) to the plugins top level folder in your GBStudio project.

### License
All code is released under the Unlicense into the public domain, this includes the dictionary and the example GBStudio project.

If used in a project attirbution is welcome but not required.

### Size
The whole thing takes about 9 ROM banks.

There is a matching test dictionary for validation in the example program which takes ~12 ROM banks. The test data is not meant to be included in user programs.

### Copying dictionary source files
If the dictionary source files are changed then the updated ones can be copied from the [src/data/](src/data/) directory into the GBStudio `plugins/Dictionary/engine/src/data/` directory.

