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

// Tools
#define _RFUIInterfaceOrientationSupport_ShouldAutorotate \
- (BOOL)shouldAutorotate {\
    return YES;\
}

#define _RFUIInterfaceOrientationSupport_SupportedInterfaceOrientations(iPhoneOption, iPadOption) \
- (NSUInteger)supportedInterfaceOrientations {\
    if ([UIDevice currentDevice].isPad) {\
        return iPadOption;\
    }\
    else {\
        return iPhoneOption;\
    }\
}

#define _RFUIInterfaceOrientationSupport_SupportedInterfaceOrientationsBoth(Option) \
- (NSUInteger)supportedInterfaceOrientations {\
    return Option;\
}


#pragma mark - Rule

// iPhone Only Portrait, no upside down
// iPad All
#define RFUIInterfaceOrientationSupportDefault \
    _RFUIInterfaceOrientationSupport_ShouldAutorotate\
    _RFUIInterfaceOrientationSupport_SupportedInterfaceOrientations(UIInterfaceOrientationMaskPortrait, UIInterfaceOrientationMaskAll)\
    \
    - (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation {\
        if ([UIDevice currentDevice].isPad) {\
            return YES;\
        }\
        else {\
            return (toInterfaceOrientation == UIInterfaceOrientationPortrait);\
        }\
    }

// iPhone Only Portrait, no upside down
// iPad Portrait + PortraitUpsideDown
#define RFUIInterfaceOrientationSupportPortrait \
    _RFUIInterfaceOrientationSupport_ShouldAutorotate\
    _RFUIInterfaceOrientationSupport_SupportedInterfaceOrientations(UIInterfaceOrientationMaskPortrait, (UIInterfaceOrientationMaskPortrait|UIInterfaceOrientationMaskPortraitUpsideDown))\
    \
    - (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation {\
        if ([UIDevice currentDevice].isPad) {\
            return UIInterfaceOrientationIsPortrait(toInterfaceOrientation);\
        }\
        else {\
            return (UIInterfaceOrientationPortrait == toInterfaceOrientation);\
        }\
    }

// iPhone & iPad Only Landscape (Left+Right)
#define RFUIInterfaceOrientationSupportLandscape \
    _RFUIInterfaceOrientationSupport_ShouldAutorotate\
    _RFUIInterfaceOrientationSupport_SupportedInterfaceOrientationsBoth(UIInterfaceOrientationMaskLandscape)\
    \
    - (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation {\
        return UIInterfaceOrientationIsLandscape(toInterfaceOrientation);\
    }

// All, except PortraitUpsideDown on iPhone
#define RFUIInterfaceOrientationSupportAll \
    _RFUIInterfaceOrientationSupport_ShouldAutorotate\
    _RFUIInterfaceOrientationSupport_SupportedInterfaceOrientations(UIInterfaceOrientationMaskAllButUpsideDown, UIInterfaceOrientationMaskAll)\
    \
    - (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation {\
        if ([UIDevice currentDevice].isPad) {\
            return YES;\
        }\
        else {\
            return (UIInterfaceOrientationPortraitUpsideDown != toInterfaceOrientation);\
        }\
    }

#pragma mark -

// Let navigation controller rotate according to current view controller
// May not fallback to topViewController on iOS 5.
#define RFUIInterfaceOrientationSupportNavigation \
    - (BOOL)shouldAutorotate {\
        return [self.topViewController shouldAutorotate];\
    }\
    \
    - (NSUInteger)supportedInterfaceOrientations {\
        return [self.topViewController supportedInterfaceOrientations];\
    }


#pragma mark -

// For disable
#define _RFUIInterfaceOrientationSupportDefault
#define _RFUIInterfaceOrientationSupportPortrait
#define _RFUIInterfaceOrientationSupportLandscape
#define _RFUIInterfaceOrientationSupportAll

#define _RFUIInterfaceOrientationSupportNavigation

#endif
