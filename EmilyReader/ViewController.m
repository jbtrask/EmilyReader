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
    self.reader = [[EasyReadingViewController alloc] initWithClientID:@"sxpjwjjoi3u0sfljtcusez8knpo2q22q" secret:@"dO29dedfySjzFOQ2z2WLYExEh6hIiCF8" delegate:self success:^{
        [UIView animateWithDuration:0.4 animations:^{
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
        CGRect heartRect = CGRectInset(self.view.bounds, 10, 80);
        self.heartView = [[UIImageView alloc] initWithFrame:heartRect];
        self.heartView.contentMode = UIViewContentModeScaleToFill;
        self.heartView.image = [UIImage imageNamed:@"heart1"];
        self.heartView.alpha = 0.0;
        self.heartView.transform = CGAffineTransformMakeScale(0.1, 0.1);
        [self.reader.view addSubview:self.heartView];
        [UIView animateWithDuration:1.0 animations:^{
            self.heartView.alpha = 0.4;
            self.heartView.transform = CGAffineTransformIdentity;
        }];
    }];
}

#pragma mark - EasyReadingDelegate

-(void)readerError:(NSError *)error
{
    NSLog(@"READER ERROR:  %@", error);
}

@end
