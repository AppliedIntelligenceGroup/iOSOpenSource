//
//  OpenSourceThreadSafeNSDateFormatter.h
//  iOSOpenSource | Applied Intelligence Group LLC | alex@appliedintelligencegrouphq.com
//
//  License: Open Source GPL v3
//  Created by Alex Horovitz on 11/12/2012
//
//  
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// The above license notice and this permission notice shall remain in place
// in this source code.

#import <Foundation/Foundation.h>
/** @discussion Singleton that provides for thread safe date formatting.
 *  Out of the box, NSDateFormatters are not thread safe; because of this, you can 
 *  arrive at a state where a background thread will attempt to use the same formatter
 *  at the same time - and this will create what appears to be random crashes. Using this
 *  approach, you can cut down the need to instantiate a new date formatter each time you
 *  need one by creating on per thread.
 */


@interface OpenSourceThreadSafeNSDateFormatter : NSObject
+ (OpenSourceThreadSafeNSDateFormatter *)sharedInstance;

/**
 * Returns the singleton instance of NSDateFormatter for the thread in question, if there 
 * is no instantiated NSDateFormatter for that thread, one is initialized and inserted into
 * the thread dictionary
 * @return Singleton instance of NSDateFormatter for the current thread.
 */

- (NSDateFormatter *)dateWriter;

/**
 * Returns the singleton instance of NSDateFormatter for the thread in question, if there 
 * is no instantiated NSDateFormatter for that thread, one is initialized and inserted into
 * the thread dictionary.
 * @param aStyle is to use a formatter style other than the default ( en_US_POSIX )
 * @return Singleton instance of NSDateFormatter for the current thread.
 */

- (NSDateFormatter *)dateWriterWithStyle:(NSDateFormatterStyle)aStyle;

@end
