//
//  OCMockDefines.h
//  OCMock
//
//  Created by Shane Zatezalo on 5/4/15.
//  Copyright (c) 2015 Mulle Kybernetik. All rights reserved.
//

#ifndef OCMock_OCMockDefines_h
#define OCMock_OCMockDefines_h

#define OCMClassMock(cls) [OCMockObject niceMockForClass:cls]

#define OCMStrictClassMock(cls) [OCMockObject mockForClass:cls]

#define OCMProtocolMock(protocol) [OCMockObject niceMockForProtocol:protocol]

#define OCMStrictProtocolMock(protocol) [OCMockObject mockForProtocol:protocol]

#define OCMPartialMock(obj) [OCMockObject partialMockForObject:obj]

#define OCMObserverMock() [OCMockObject observerMock]


#define OCMStub(invocation) \
({ \
_OCMSilenceWarnings( \
[OCMMacroState beginStubMacro]; \
invocation; \
[OCMMacroState endStubMacro]; \
); \
})

#define OCMExpect(invocation) \
({ \
_OCMSilenceWarnings( \
[OCMMacroState beginExpectMacro]; \
invocation; \
[OCMMacroState endExpectMacro]; \
); \
})

#define ClassMethod(invocation) \
_OCMSilenceWarnings( \
[[OCMMacroState globalState] switchToClassMethod]; \
invocation; \
);


#define OCMVerifyAll(mock) [mock verifyAtLocation:OCMMakeLocation(self, __FILE__, __LINE__)]

#define OCMVerifyAllWithDelay(mock, delay) [mock verifyWithDelay:delay atLocation:OCMMakeLocation(self, __FILE__, __LINE__)]

#define OCMVerify(invocation) \
({ \
_OCMSilenceWarnings( \
[OCMMacroState beginVerifyMacroAtLocation:OCMMakeLocation(self, __FILE__, __LINE__)]; \
invocation; \
[OCMMacroState endVerifyMacro]; \
); \
})

#define _OCMSilenceWarnings(macro) \
({ \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wunused-value\"") \
macro \
_Pragma("clang diagnostic pop") \
})

#endif
