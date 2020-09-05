module ApolloCache = ApolloClient__Cache_Core_Cache.ApolloCache;
module CanReadFunction = ApolloClient__Cache_Core_Types_Common.CanReadFunction;
module FieldNode = ApolloClient__Graphql.Language.Ast.FieldNode;
module ReadFieldFunction = ApolloClient__Cache_Core_Types_Common.ReadFieldFunction;
module ToReferenceFunction = ApolloClient__Cache_Core_Types_Common.ToReferenceFunction;

module FieldMergeFunction = {
  module Js_ = {
    type t;
  };
  type t = Js_.t;
};

module StorageType = {
  type t = Js.Dict.t(Js.Json.t);
  module Js_ = {
    type nonrec t = t;
  };
};

module FieldFunctionOptions = {
  type useMethodFunctionInThisModuleInstead;
  module Js_ = {
    // export interface FieldFunctionOptions<TArgs = Record<string, any>, TVars = Record<string, any>> {
    //     args: TArgs | null;
    //     fieldName: string;
    //     storeFieldName: string;
    //     field: FieldNode | null;
    //     variables?: TVars;
    //     isReference: typeof isReference;
    //     toReference: ToReferenceFunction;
    //     storage: StorageType | null;
    //     cache: InMemoryCache;
    //     readField: ReadFieldFunction;
    //     canRead: CanReadFunction;
    //     mergeObjects<T extends StoreObject | Reference>(existing: T, incoming: T): T | undefined;
    // }
    type t = {
      args: Js.nullable(Js.Dict.t(Js.Json.t)),
      fieldName: string,
      storeFieldName: string,
      field: Js.nullable(FieldNode.t),
      variables: option(Js.Dict.t(Js.Json.t)),
      isReference: bool,
      toReference: useMethodFunctionInThisModuleInstead,
      storage: Js.nullable(StorageType.Js_.t),
      cache: ApolloCache.Js_.t(Js.Json.t),
      readField: useMethodFunctionInThisModuleInstead,
      canRead: useMethodFunctionInThisModuleInstead,
      mergeObjects: useMethodFunctionInThisModuleInstead,
    };
  };

  type t =
    Js_.t = {
      args: Js.nullable(Js.Dict.t(Js.Json.t)),
      fieldName: string,
      storeFieldName: string,
      field: Js.nullable(FieldNode.t),
      variables: option(Js.Dict.t(Js.Json.t)),
      isReference: bool,
      toReference: useMethodFunctionInThisModuleInstead,
      storage: Js.nullable(StorageType.t),
      cache: ApolloCache.Js_.t(Js.Json.t),
      readField: useMethodFunctionInThisModuleInstead,
      canRead: useMethodFunctionInThisModuleInstead,
      mergeObjects: useMethodFunctionInThisModuleInstead,
    };

  [@bs.send] external canRead: t => CanReadFunction.Js_.t = "canRead";
  [@bs.send]
  external mergeObjects:
    (t, ~existing: Js.Json.t, ~incoming: Js.Json.t) => option(Js.Json.t) =
    "canRead";
  [@bs.send] external readField: t => ReadFieldFunction.Js_.t = "readField";
  [@bs.send] external toReference: t => ToReferenceFunction.t = "toReference";
};

module FieldReadFunction = {
  type t = (Js.Json.t, FieldFunctionOptions.t) => Js.Json.t;

  module Js_ = {
    // export declare type FieldReadFunction<TExisting = any, TReadResult = TExisting> = (existing: SafeReadonly<TExisting> | undefined, options: FieldFunctionOptions) => TReadResult | undefined;
    type t = (Js.Json.t, FieldFunctionOptions.Js_.t) => Js.Json.t;
  };
};

module KeySpecifier = {
  type t = array(string);
  module Js_ = {
    // declare type KeySpecifier = (string | any[])[];
    type nonrec t = t;
  };
};

module KeyArgsFunction = {
  type t_context = {
    typename: string,
    fieldName: string,
    field: Js.null(FieldNode.t),
    variables: option(Js.Json.t),
  };

  type t = (Js.nullable(Js.Json.t), t_context) => KeySpecifier.t;

  module Js_ = {
    // export declare type KeyArgsFunction = (args: Record<string, any> | null, context: {
    //     typename: string;
    //     fieldName: string;
    //     field: FieldNode | null;
    //     variables?: Record<string, any>;
    // }) => KeySpecifier | ReturnType<IdGetter>;
    type nonrec t = t;
  };
};

module FieldPolicy_KeyArgs = {
  type t =
    | KeySpecifier(KeySpecifier.t)
    | KeyArgsFunction(KeyArgsFunction.t)
    | False;

  module Js_ = {
    module KeyArgsUnion: {
      type t;
      let keySpecifier: KeySpecifier.Js_.t => t;
      let keyArgsFunction: KeyArgsFunction.Js_.t => t;
      let false_: t;
    } = {
      [@unboxed]
      type t =
        | Any('a): t;
      let keySpecifier = (v: KeySpecifier.Js_.t) => Any(v);
      let keyArgsFunction = (v: KeyArgsFunction.Js_.t) => Any(v);
      let false_ = Any(false);
    };

    type t = KeyArgsUnion.t;
  };

  let toJs: t => Js_.t =
    fun
    | KeySpecifier(keySpecifier) =>
      keySpecifier->Js_.KeyArgsUnion.keySpecifier
    | KeyArgsFunction(keyArgsFunction) =>
      keyArgsFunction->Js_.KeyArgsUnion.keyArgsFunction
    | False => Js_.KeyArgsUnion.false_;
};

module FieldPolicy = {
  type t = {
    keyArgs: option(FieldPolicy_KeyArgs.t),
    read: option(FieldReadFunction.t),
    merge: option(FieldMergeFunction.t),
  };

  module Js_ = {
    // export declare type FieldPolicy<TExisting = any, TIncoming = TExisting, TReadResult = TExisting> = {
    //     keyArgs?: KeySpecifier | KeyArgsFunction | false;
    //     read?: FieldReadFunction<TExisting, TReadResult>;
    //     merge?: FieldMergeFunction<TExisting, TIncoming> | boolean;
    // };
    type nonrec t = {
      keyArgs: option(FieldPolicy_KeyArgs.Js_.t),
      read: option(FieldReadFunction.t),
      merge: option(FieldMergeFunction.t),
    };
  };

  let toJs: t => Js_.t =
    t => {
      keyArgs: t.keyArgs->Belt.Option.map(FieldPolicy_KeyArgs.toJs),
      read: t.read,
      merge: t.merge,
    };
};
