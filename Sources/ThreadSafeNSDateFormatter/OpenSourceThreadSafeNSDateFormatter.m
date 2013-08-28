//
//  OpenSourceThreadSafeNSDateFormatter.m
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

#import "OpenSourceThreadSafeNSDateFormatter.h"
#import "GCDSingleton.h"



@interface OpenSourceThreadSafeNSDateFormatter (PrivateMethods)

- _init;

@end

@implementation OpenSourceThreadSafeNSDateFormatter


+ (OpenSourceThreadSafeNSDateFormatter *)sharedInstance
{
    DEFINE_SHARED_INSTANCE_USING_BLOCK(^{
        return [[self alloc] _init];
    });
}

- (id)init
{
    return nil;
}

- _init
{
    self = [super init];
    return self;
}


- (NSDateFormatter *)dateWriter
{
    NSMutableDictionary *dictionary = [[NSThread currentThread] threadDictionary];
    NSDateFormatter *df = [dictionary objectForKey:@"OSDateReader"];
    if (!df)
    {
        df = [[NSDateFormatter alloc] init];
        df.locale = [[NSLocale alloc] initWithLocaleIdentifier:@"en_US_POSIX"];
        df.timeZone = [NSTimeZone systemTimeZone];
        df.dateFormat = @"EEE, dd MMM yyyy HH:mm:ss Z";
        [dictionary setObject:df forKey:@"OSDateWriter_en_US_POSIX"];
    }
    return df;
}



- (NSDateFormatter *)dateWriterWithStyle:(NSDateFormatterStyle)aStyle
{
    NSMutableDictionary *dictionary = [[NSThread currentThread] threadDictionary];
    NSDateFormatter *df = [dictionary objectForKey:@"OSDateWriter"];
    if (!df)
    {
        df = [[NSDateFormatter alloc] init];
        df.locale = [NSLocale currentLocale];
        df.timeZone = [NSTimeZone systemTimeZone];
        df.dateStyle = aStyle;
        df.timeStyle = NSDateFormatterShortStyle;
        [dictionary setObject:df forKey:@"OSDateWriter"];
    }
    return df;
}


@end