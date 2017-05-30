# Electron Builder

electron-builder sample for distribution Electron app for macOS and Windows.

## Documentations

* electron-builder
  * https://github.com/electron-userland/electron-builder


## Install modules
```
$ npm install electron --save-dev
$ npm install electron-builder --save-dev
```

```
$ sw_vers
ProductName:	Mac OS X
ProductVersion:	10.11.6

$ ./node_modules/.bin/electron -v
v1.6.7

$ ./node_modules/.bin/build --version
17.5.0
```

### for Windows
* Install "NSIS" from http://nsis.sourceforge.net/Download

### for macOS
```
$ brew install wine
$ wine --version
wine-1.8.5
```

## Build package
```
$ npm run pack
```
