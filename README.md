A simple dictionary word validator for use with GBDK / ZGB / GBStudio which supports ROM banking.

At present it's a quick and simple implementation with support for words 3-6 letters long. 
While not as fast and size efficient as the [GB-wordyl](https://github.com/bbbbbr/gb-wordyl) 
dictionary, it's far less complicated and should be easier to understand, modify and use in other projects.

There is lookup function code duplication in the banked sources as a result of trying to use as little
Bank 0 space as possible, since that space is sometimes in short very supply in GBStudio projects using
plugins.

### GB Studio example project
EGVroom has provided an example GBStudio project (under `GBStudioLookUpDemo`) showing how to interface with and use the dictionary. A pre-built example ROM is included in the project under `GBStudioLookUpDemo/build/rom`.

### License
All code is released inther the Unlicense into the public domain, this includes the dictionary and the example GBStudio project.

If used in a project attirbution is welcome but not required.

### Size
The whole thing takes about 9 ROM banks.

There is a matching test dictionary for validation in the example program which takes ~12 ROM banks. The test data is not meant to be included in user programs.

### Copying dictionary source files
Copy the contents of the `src/data/` directory into the GBStudio `assets/engine/src/data/` directory.

### Interfacing with the code
See the `native_testfunc.c` example under `GBStudioLookUpDemo/assets/engine/src/data/sounds`.


