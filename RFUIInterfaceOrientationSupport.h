/*!
    RFUIInterfaceOrientationSupport
    RFUI

    Copyright (c) 2012-2013 BB9z
    https://github.com/RFUI/Core

    The MIT License (MIT)
    http://www.opensource.org/licenses/mit-license.php
 */

#ifndef _RFUIInterfaceOrientationSupport_
#define _RFUIInterfaceOrientationSupport_

// iPhone AllButUpsideDown
// iPad All
#define RFUIInterfaceOrientationSupportDefault \
    - (BOOL)shouldAutorotate {\
        return YES;\
    }\
    \
    - (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation {\
        if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {\
            return UIInterfaceOrientationIsPortrait(toInterfaceOrientation);\
        }\
        else {\
            return YES;\
        }\
    }\
    \
    - (NSUInteger)supportedInterfaceOrientations {\
        if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {\
            return UIInterfaceOrientationMaskAllButUpsideDown;\
        }\
        else {\
            return UIInterfaceOrientationMaskAll;\
        }\
    }

// iPhone Only Portrait
// iPad Portrait + PortraitUpsideDown
#define RFUIInterfaceOrientationSupportPortrait \
    - (BOOL)shouldAutorotate {\
        return YES;\
    }\
    \
    - (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation {\
        if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {\
            return UIInterfaceOrientationPortrait == toInterfaceOrientation;\
        }\
        else {\
            return UIInterfaceOrientationIsPortrait(toInterfaceOrientation);\
        }\
    }\
    \
    - (NSUInteger)supportedInterfaceOrientations {\
        if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {\
            return UIInterfaceOrientationMaskPortrait;\
        }\
        else {\
            return UIInterfaceOrientationMaskPortrait | UIInterfaceOrientationMaskPortraitUpsideDown;\
        }\
    }

// iPhone & iPad Only Landscape (Left+Right)
#define RFUIInterfaceOrientationSupportLandscape \
    - (BOOL)shouldAutorotate {\
        return YES;\
    }\
    \
    - (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation {\
        return UIInterfaceOrientationIsLandscape(toInterfaceOrientation);\
    }\
    \
    - (NSUInteger)supportedInterfaceOrientations {\
        return UIInterfaceOrientationMaskLandscape;\
    }

// All
#define RFUIInterfaceOrientationSupportAll \
    - (BOOL)shouldAutorotate {\
        return YES;\
    }\
    \
    - (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation {\
        return YES;\
    }\
    \
    - (NSUInteger)supportedInterfaceOrientations {\
        return UIInterfaceOrientationMaskAll;\
    }

#define _RFUIInterfaceOrientationSupportDefault RFUIInterfaceOrientationSupportAll
#define _RFUIInterfaceOrientationSupportPortrait RFUIInterfaceOrientationSupportAll
#define _RFUIInterfaceOrientationSupportLandscape RFUIInterfaceOrientationSupportAll
#define _RFUIInterfaceOrientationSupportAll RFUIInterfaceOrientationSupportAll

#endif
