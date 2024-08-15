A simple dictionary word validator for use with GBDK / ZGB / GBStudio which supports ROM banking.

At present it's a quick and simple implementation with support for words 3-6 letters long. 
While not nearly as fast and size efficient as the [GB-wordyl](https://github.com/bbbbbr/gb-wordyl) 
dictionary, it's far less complicated and should be easier to understand, modify and use in other projects.

There is lookup function code duplication in the banked sources as a result of trying to use as little
Bank 0 space as possible, since that space is sometimes in short very supply in GBStudio projects using
plugins.

**Size**
The whole thing takes about 9 ROM banks.

There is a matching test dictionary for validation in the example program which takes ~12 ROM banks. The test data is not meant to be included in user programs.

### Copy dictionary source files
Copy the contents of the `src/data/` directory into the GBStudio `assets/engine/src/data/` directory

