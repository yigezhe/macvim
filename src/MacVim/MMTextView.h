/* vi:set ts=8 sts=4 sw=4 ft=objc:
 *
 * VIM - Vi IMproved		by Bram Moolenaar
 *				MacVim GUI port by Bjorn Winckler
 *
 * Do ":help uganda"  in Vim to read copying and usage conditions.
 * Do ":help credits" in Vim to see a list of people who contributed.
 * See README.txt for an overview of the Vim source code.
 */

#import <Cocoa/Cocoa.h>


@interface MMTextView : NSTextView {
    BOOL                shouldDrawInsertionPoint;
    NSTrackingRectTag   trackingRectTag;
    BOOL                isDragging;
    BOOL                isAutoscrolling;
    int                 dragRow;
    int                 dragColumn;
    int                 dragFlags;
    NSPoint             dragPoint;
    int                 insertionPointRow;
    int                 insertionPointColumn;
    int                 insertionPointShape;
    int                 insertionPointFraction;
    NSRange             imRange;
    NSRange             markedRange;
    NSDictionary        *markedTextAttributes;
    NSMutableAttributedString  *markedText;
    int                 preEditRow;
    int                 preEditColumn;
    int                 mouseShape;
    BOOL                antialias;
    NSRect              *invertRects;
    int                 numInvertRects;
}

- (id)initWithFrame:(NSRect)frame;

- (void)setShouldDrawInsertionPoint:(BOOL)on;
- (void)setPreEditRow:(int)row column:(int)col;
- (void)performBatchDrawWithData:(NSData *)data;
- (void)setMouseShape:(int)shape;
- (void)setAntialias:(BOOL)antialias;

//
// MMTextStorage methods
//
- (NSFont *)font;
- (void)setFont:(NSFont *)newFont;
- (void)setWideFont:(NSFont *)newFont;
- (NSSize)cellSize;
- (void)setLinespace:(float)newLinespace;
- (void)getMaxRows:(int*)rows columns:(int*)cols;
- (void)setMaxRows:(int)rows columns:(int)cols;
- (NSRect)rectForRowsInRange:(NSRange)range;
- (NSRect)rectForColumnsInRange:(NSRange)range;
- (void)setDefaultColorsBackground:(NSColor *)bgColor
                        foreground:(NSColor *)fgColor;

- (NSSize)constrainRows:(int *)rows columns:(int *)cols toSize:(NSSize)size;
- (NSSize)desiredSize;
- (NSSize)minSize;

@end
