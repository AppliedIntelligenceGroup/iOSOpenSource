//
//  GCDSingleton.h
//  iOSOpenSource | Applied Intelligence Group LLC | alex@appliedintelligencegrouphq.com
//
//  License: Open Source GPL v3
//  Created by Alex Horovitz on 11/03/2012
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

#ifndef OpenSource_GCDSingleton_h
#define OpenSource_GCDSingleton_h




/*
@implementation MySharedThing

// Using method 1
//
DEFINE_SHARED_INSTANCE_FOR_CLASS(MySharedThing)

// Using method 2
//
+ (id)sharedInstance
{
      DEFINE_SHARED_INSTANCE_USING_BLOCK(^{
            return [[self alloc] init];
          });
}

@end
*/

//
//  METHOD #1: use this if you want the sharedInstance method to be 'sharedClassName'
//
//  @implementation MySharedThing
//
//  DEFINE_SHARED_INSTANCE_FOR_CLASS(MySharedThing)
//


/** @discussion These macros simplify creating of a sharedInstance for a class using GCD (ARC compliant)
 *
 *  You will need to edit this header depending on which approach you wish to take.
 *  
 *  METHOD #1: You will use this method if you want the sharedInstance method to be 'sharedClassName'
 *  
 *  METHOD #2: You will use this method if you want to name the 'sharedXXX' method yourself
 */

#define DEFINE_SHARED_INSTANCE_FOR_CLASS(className) \
+ (id)shared##className \
{ \
static dispatch_once_t pred = 0; \
__strong static id _sharedObject = nil; \
dispatch_once(&pred, ^{ \
_sharedObject = ^{return [[self alloc] init];}(); \
}); \
return _sharedObject; \
} \


//
// METHOD #2: use this if you want to name the 'sharedXXX' method yourself
//
//  @implementation MySharedThing
//
//  + (id)sharedInstance
//  {
//      DEFINE_SHARED_INSTANCE_USING_BLOCK(^{
//          return [[self alloc] init];
//      });
//  }
//
//  @end
//

#define DEFINE_SHARED_INSTANCE_USING_BLOCK(block) \
static dispatch_once_t pred = 0; \
__strong static id _sharedObject = nil; \
dispatch_once(&pred, ^{ \
_sharedObject = block(); \
}); \
return _sharedObject; \

#endif
