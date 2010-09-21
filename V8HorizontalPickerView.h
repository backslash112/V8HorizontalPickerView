//
//  V8HorizontalPickerView.h
//
//  Created by Shawn Veader on 9/17/10.
//  Copyright 2010 V8 Labs, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "V8HorizontalPickerViewProtocol.h"

@interface V8HorizontalPickerView : UIView <UIScrollViewDelegate> {
	UIScrollView *_scrollView;

	id <V8HorizontalPickerViewDataSource> dataSource;
	id <V8HorizontalPickerViewDelegate> delegate;

	NSMutableArray *elementWidths;
	NSMutableSet *reusableViews;

	UIFont *elementFont;

	UIColor *textColor;
	UIColor *selectedTextColor;
	UIColor *theBackgroundColor;
	
	NSInteger numberOfElements;
	NSInteger elementPadding;
	NSInteger endsPadding;
	NSInteger currentSelectedIndex;

	BOOL dataHasBeenLoaded;
	BOOL scrollSizeHasBeenSet;
}

@property (nonatomic, assign) id <V8HorizontalPickerViewDataSource> dataSource;
@property (nonatomic, assign) id <V8HorizontalPickerViewDelegate> delegate;
@property (nonatomic, readonly) NSInteger numberOfElements;
@property (nonatomic, retain) UIFont *elementFont;
@property (nonatomic, retain) UIColor *textColor;
@property (nonatomic, retain) UIColor *selectedTextColor;
@property (nonatomic, retain) UIColor *theBackgroundColor;

- (UIView *)dequeueReusableView;
- (void)scrollToElement:(NSInteger)index animated:(BOOL)animate;
- (void)reloadData;

@end
