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

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (IBAction)showReaderTapped:(id)sender {
    self.reader = [[EasyReadingViewController alloc] initWithClientID:@"sxpjwjjoi3u0sfljtcusez8knpo2q22q" secret:@"dO29dedfySjzFOQ2z2WLYExEh6hIiCF8" delegate:self success:^{
        self.reader.view.frame = self.view.bounds;
        [self presentViewController:self.reader animated:YES completion:nil];
    } failure:^(NSError *error) {
        NSLog(@"READER ERROR:  %@", error);
    }];
}

#pragma mark - EasyReadingDelegate

-(void)readerError:(NSError *)error
{
    NSLog(@"READER ERROR:  %@", error);
}

@end
