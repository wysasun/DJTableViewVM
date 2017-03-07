//
//  DJTableViewVMTextViewCellRow.h
//  DJComponentTableViewVM
//
//  Created by Dokay on 2017/3/1.
//  Copyright © 2017年 dj226. All rights reserved.
//

#import "DJTableViewVMInputBaseRow.h"

NS_ASSUME_NONNULL_BEGIN

#define DJTableViewVMTextViewCellRowMagicMarginNumber 5

@interface DJTableViewVMTextViewCellRow : DJTableViewVMInputBaseRow

@property(nonatomic, nullable, copy)NSString *placeholder;
@property(nonatomic, strong) UIColor *placeholderColor;
@property(nonatomic, strong) UIFont *placeholderFont;
@property(nonatomic, strong) NSAttributedString *attributedPlaceholder;

@property(nonatomic, assign) CGFloat textFiledLeftMargin;
@property(nonatomic, assign) UIEdgeInsets textContainerInset;

@property(nonatomic, assign) BOOL showCharactersCount;
@property(nonatomic, assign) NSUInteger charactersMaxCount;
@property(nonatomic, strong) UIColor *charactersCountColor;
@property(nonatomic, strong) UIFont *charactersCountFont;

// Presented when object becomes first responder.  If set to nil, reverts to following responder chain.  If
// set while first responder, will not take effect until reloadInputViews is called.
@property (nullable, readwrite, strong) UIView *inputView;

@property(nullable,nonatomic,copy) NSString *text;
@property(nullable,nonatomic,strong) UIFont *font;
@property(nullable,nonatomic,strong) UIColor *textColor;
@property(nonatomic) NSTextAlignment textAlignment;    // default is NSLeftTextAlignment
@property(nonatomic) NSRange selectedRange;
@property(nonatomic,getter=isEditable) BOOL editable;
@property(nonatomic,getter=isSelectable) BOOL selectable NS_AVAILABLE_IOS(7_0); // toggle selectability, which controls the ability of the user to select content and interact with URLs & attachments
@property(nonatomic) UIDataDetectorTypes dataDetectorTypes NS_AVAILABLE_IOS(3_0);

@property(nonatomic) BOOL allowsEditingTextAttributes NS_AVAILABLE_IOS(6_0); // defaults to NO
@property(nullable,copy) NSAttributedString *attributedText NS_AVAILABLE_IOS(6_0);
@property(nonatomic,copy) NSDictionary<NSString *, id> *typingAttributes NS_AVAILABLE_IOS(6_0); // automatically resets when the selection changes

#pragma mark - actions
@property (nonatomic, copy) void (^textChanged)(DJTableViewVMTextViewCellRow *rowVM);
@property (nonatomic, copy) void (^didBeginEditing)(DJTableViewVMTextViewCellRow *rowVM);
@property (nonatomic, copy) void (^didEndEditing)(DJTableViewVMTextViewCellRow *rowVM);
@property (nonatomic, copy) void (^maxCountInputMore)(DJTableViewVMTextViewCellRow *rowVM);
@property (nonatomic, copy) void (^didChangeSelection)(DJTableViewVMTextViewCellRow *rowVM, NSRange selectedRange);
@property (nonatomic, copy) BOOL (^shouldBeginEditing)(DJTableViewVMTextViewCellRow *rowVM);
@property (nonatomic, copy) BOOL (^shouldEndEditing)(DJTableViewVMTextViewCellRow *rowVM);
@property (nonatomic, copy) BOOL (^shouldChangeCharacterInRange)(DJTableViewVMTextViewCellRow *rowVM, NSRange range, NSString *replacementString);

@end

NS_ASSUME_NONNULL_END