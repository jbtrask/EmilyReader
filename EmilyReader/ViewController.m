//
//  ViewController.m
//  EmilyReader
//
//  Created by James Trask on 6/22/15.
//  Copyright (c) 2015 Code Joy Inc. All rights reserved.
//

@import LinkReaderKit;

#import "ViewController.h"

@interface ViewController () <EasyReadingDelegate>

@property (nonatomic, strong) EasyReadingViewController *reader;
@property (weak, nonatomic) IBOutlet UILabel *titleLabel;
@property (strong, nonatomic) UIImageView *heartView;

@end

@implementation ViewController

NSString * const kClientID = @"sxpjwjjoi3u0sfljtcusez8knpo2q22q";
NSString * const kClientSecret = @"dO29dedfySjzFOQ2z2WLYExEh6hIiCF8";

CGFloat kTitleFadeOutDuration = 0.4;
CGFloat kHeartWidth = 320.0;
CGFloat kHeartInitialScale = 0.1;
CGFloat kHeartFinalAlpha = 0.4;
CGFloat kHeartFadeInDuration = 1.0;

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    if (self.reader) {
        [self showReader];
    } else {
        [self initReader];
    }
}

- (void)initReader {
    self.reader = [[EasyReadingViewController alloc] initWithClientID:kClientID secret:kClientSecret delegate:self success:^{
        [UIView animateWithDuration:kTitleFadeOutDuration animations:^{
            self.titleLabel.alpha = 0.0;
        } completion:^(BOOL finished) {
            [self showReader];
        }];
    } failure:^(NSError *error) {
        NSLog(@"READER ERROR:  %@", error);
    }];
}

- (void)showReader
{
    if (self.heartView) {
        [self.heartView removeFromSuperview];
        self.heartView = nil;
    }
    
    self.reader.view.frame = self.view.bounds;
    [self presentViewController:self.reader animated:YES completion:^{
        [self addHeart];
        [UIView animateWithDuration:kHeartFadeInDuration animations:^{
            self.heartView.alpha = kHeartFinalAlpha;
            self.heartView.transform = CGAffineTransformIdentity;
        }];
    }];
}

// Constraints adapted from https://github.com/evgenyneu/center-vfl
- (void)addHeart
{
    self.heartView = [[UIImageView alloc] initWithFrame:CGRectZero];
    self.heartView.contentMode = UIViewContentModeScaleToFill;
    self.heartView.image = [UIImage imageNamed:@"heart1"];
    self.heartView.alpha = 0.0;
    self.heartView.transform = CGAffineTransformMakeScale(kHeartInitialScale, kHeartInitialScale);
    self.heartView.autoresizingMask = UIViewAutoresizingNone;
    [self.heartView setTranslatesAutoresizingMaskIntoConstraints:NO];
    [self.reader.view addSubview:self.heartView];
    
    NSDictionary *views = @{ @"superview":self.reader.view, @"heartView":self.heartView };
    NSDictionary *values = @{
                             @"width":[NSNumber numberWithFloat:kHeartWidth]
                             };
    
    
    NSArray *horizontalConstraints = [NSLayoutConstraint constraintsWithVisualFormat:@"V:[superview]-(<=1)-[heartView(width)]" options:NSLayoutFormatAlignAllCenterX metrics:values views:views];
    NSArray *verticalConstraints = [NSLayoutConstraint constraintsWithVisualFormat:@"H:[superview]-(<=1)-[heartView(width)]" options:NSLayoutFormatAlignAllCenterY metrics:values views:views];
    NSMutableArray *constraints = [NSMutableArray arrayWithArray:horizontalConstraints];
    [constraints addObjectsFromArray:verticalConstraints];
    
    [NSLayoutConstraint activateConstraints:constraints];
}

#pragma mark - EasyReadingDelegate

-(void)readerError:(NSError *)error
{
    NSLog(@"READER ERROR:  %@", error);
}

@end
