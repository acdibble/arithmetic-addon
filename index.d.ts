// Type definitions for Arithmetic

export = Arithmetic;

declare class Arithmetic {
  constructor();

  /**
   * An internal register for the calcualtion that is not exposed
   */
  private total: number;

  /**
   * Adds `num` to `total`
   */
  add(num: number): void;

  /**
   * Subtracts `num` from `total`
   */
  sub(num: number): void;

  /**
   * Multiplies `total` by `num` and sets the product to `total`
   */
  mul(num: number): void;

  /**
   * Performs floor division on `total` with `num` and sets the quotient to `total`
   */
  div(num: number): void;

  /**
   * Returns `total` and resets it to `0`
   */
  getTotal(): number;
}
