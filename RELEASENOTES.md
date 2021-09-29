# Summary of changes

## Changes for version 1.1.4 (29 Sep 2021)

### Bug Fixes

- Added configurations for the Snow project into continuous integration


## Changes for version 1.1.3 (14 Sep 2021)

### Bug Fixes

- Moved continuous integration to Jenkins
- Deploy conan package into remote specific for C++ task force
- Fixed use of "export_sources" definition in conan recipe


## Changes for version 1.1.2 (30 Mar 2021)

### Bug Fixes

- Upload generated packages to CSW JFrogPlatform
- Moved VS2017 configurations to work with GoogleTest 1.10.0


## Changes for version 1.1.1 (25 Feb 2021)

### Bug Fixes

- Updated continuous integration to:
  - Use GitHub Action to generate library documentation
  - Upload generated packages to Systelab's public Artifactory


## Changes for version 1.1.0 (7 Sep 2020)

### Enhancements

- Added flag for pretty serialization of JSONs
- Added methods for value retrieval based on JSON pointers


## Changes for version 1.0.11 (1 Jun 2020)

### Bug Fixes

- Used conan gtest from conan-center (without username/channel)


## Changes for version 1.0.10 (18 Apr 2020)

### Bug Fixes

- Added missing method to build a new document from a value


## Changes for version 1.0.9 (14 Jan 2020)

### Bug Fixes

- Added support for GoogleTest 1.10.0
- Added support for Visual Studio 2019


## Changes for version 1.0.8 (8 Dec 2019)

### Bug Fixes

- Removed unused IJSONMember class from interface and associated mock object.


## Changes for version 1.0.7 (8 Dec 2019)

### Bug Fixes

- Add missing methods to MockJSONValue test utility


## Changes for version 1.0.6 (28 Nov 2019)

### Bug Fixes

- Fixed issue on JSON schema test utilities: checked that given documents correspond with valid JSONs.


## Changes for version 1.0.5 (28 Nov 2019)

### Bug Fixes

- Added test utilities to easily validate JSON schemas


## Changes for version 1.0.4 (9 Nov 2019)

### Bug Fixes

- Added methods to facilitate the handling of NULL values
- Added matcher for string arguments with JSON content


## Changes for version 1.0.3 (22 Oct 2019)

### Bug Fixes

- Splitted Conan packages of this repository in two:
  - JSONAdapterInterface (header only package)
  - JSONAdapterTestUtilities


## Changes for version 1.0.2 (10 Oct 2019)

### Bug Fixes

- Updated compilation configurations to include the ones required for the Snow project


## Changes for version 1.0.1 (3 Jul 2019)

### Bug Fixes

- Improved cmake and conan configuration to link only against used dependencies


## Changes for version 1.0.0 (4 Apr 2019)

### Enhancements

- Initial version on GitHub

