//
//  UICollectionViewCell+UICollectionViewCell_MTReady.m
//  MonkeyTalk
//
//  Created by Christian Klaproth on 17.09.15.
//  Copyright © 2015 Gorilla Logic, Inc. All rights reserved.
//

#import "UICollectionViewCell+MTReady.h"
#import "TouchSynthesis.h"
#import "MTCommandEvent.h"
#import "MonkeyTalk.h"

@implementation UICollectionViewCell (MTReady)

- (void) playbackMonkeyEvent:(MTCommandEvent*)event
{
    if ([event.command isEqualToString:MTCommandTap]) {
        NSLog(@"### %s tap = %@", __PRETTY_FUNCTION__, [event description]);
        for (UIView* view in self.contentView.subviews) {
            if ([NSStringFromClass(view.class) isEqualToString:@"_UIAlertControllerActionView"]) {
                NSLog(@"### found _UIAlertControllerActionView");
                UIAlertAction* action = [view performSelector:@selector(action)];
                UIAlertController* controller = [view performSelector:@selector(alertController)];
                NSLog(@"### %s dismiss alert controller %@", __PRETTY_FUNCTION__, controller);
                [controller dismissViewControllerAnimated:NO completion:[action performSelector:@selector(handler)]];
            }
        }
    }
}

@end
